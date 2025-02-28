#pragma once
#include "Core.h"
#include "Window.h"
#include "Events/Event.h"
#include "Trail/LayerStack.h"
#include "Trail/Events/ApplicationEvent.h"
namespace Trail {
	class TRL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();//run loop

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack; //the layer stack shares it's lifetime with the Application class
		static Application* s_Instance;
	};

	//TO BE DEFINED IN CLIENT
	Application* CreateApplication();
}

