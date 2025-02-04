#pragma once
#include "Core.h"
#include "Window.h"
#include "Events/Event.h"
namespace Trail {
	class TRL_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();//run loop
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//TO BE DEFINED IN CLIENT
	Application* CreateApplication();
}

