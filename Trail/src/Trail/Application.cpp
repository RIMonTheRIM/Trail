#include "Application.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"
namespace Trail {
	Application::Application() {

	}

	Application::~Application()
	{
	}
	void Application::Run() {
		WindowResizeEvent event(1280, 720);
		if(event.IsInCategory(EventCategoryApplication)) TRL_WARN("it is in EventCategoryApplication");
		TRL_TRACE(event.ToString());

		while (true);
	}
}

