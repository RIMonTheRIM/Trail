#include "trlpch.h"


#include "Application.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"
#include <glad/glad.h>
namespace Trail {


	Application* Application::s_Instance = nullptr;

	Application::Application() {
		TRL_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());//why do we need this unique pointer ? ( because we will only have a single window)
		m_Window->SetEventCallback(TRL_BIND_EVENT_FN(Application::OnEvent)); //this is set up so that when the EventCallback function from the 
		//window class gets called, it automatically calls the OnEvent function, so the only thing we need to do is to set up GLFW call backs from the window
		//and call EventCallback for every type of handled event by GLFW
	}

	void Application::PushLayer(Layer* layer) {
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}
	void Application::PushOverlay(Layer* overlay) {
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(TRL_BIND_EVENT_FN(Application::OnWindowClosed)); //this just means that the function put as a parameter inside the 
		//Dispatch function will be called if and only if the dispatcher's event is equal to this dispatcher's type (here WindowCloseEvent) and since it's bound to OnWindowClosed
		//it'll call OnWindowClosed with the parameter it received, the event
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
			(*--it)->OnEvent(e);
			if (e.Handled) {
				TRL_TRACE("EVENT HANDLED");
				break;
			}
		}
	}
	bool Application::OnWindowClosed(WindowCloseEvent& e) {
		m_Running = false; //since our run loop is dependent on m_Running being true, this function stops the application
		return true;
	}
	Application::~Application()
	{
	}
	void Application::Run() {
		while (m_Running) {
			for (Layer* layer : m_LayerStack) {
				layer->OnUpdate(); //updates every layer one by one every frame
			}

			m_Window->OnUpdate();
		}
	}
}

