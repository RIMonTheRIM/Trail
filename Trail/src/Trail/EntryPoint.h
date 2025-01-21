#pragma once

#ifdef TRL_PLATFORM_WINDOWS

extern Trail::Application* Trail::CreateApplication();

int main(int argc, char** argv) {

	Trail::Log::Init(); //initailization of the logger to be used, will be moved to a seperate initialiaztion system
	TRL_CORE_WARN("initialize log!");
	int a = 5;
	TRL_INFO("hello Var={0}", a);
	printf("Trail Engine");
	auto app = Trail::CreateApplication(); //this just returns a new sandbox
	app->Run();//can be ran because Sandbox class inherits Application class from the dll
	delete app;
}
#endif