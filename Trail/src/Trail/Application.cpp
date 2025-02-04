#include "trlpch.h"


#include "Application.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"
namespace Trail {
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());//why do we need this unique pointer ?
	}

	Application::~Application()
	{
	}
	void Application::Run() {
		while (m_Running) {
			m_Window->OnUpdate();
		}
	}
}

