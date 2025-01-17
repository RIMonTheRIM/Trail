#pragma once
#include "Core.h"

namespace Trail {
	class TRL_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();//run loop
	};

	//TO BE DEFINED IN CLIENT
	Application* CreateApplication();
}

