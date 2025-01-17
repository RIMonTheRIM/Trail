#pragma once

#ifdef TRL_PLATFORM_WINDOWS

extern Trail::Application* Trail::CreateApplication();

int main(int argc, char** argv) {
	printf("Trail Engine");
	auto app = Trail::CreateApplication(); //this just returns a new sandbox
	app->Run();//can be ran because Sandbox class inherits Application class from the dll
	delete app;
}
#endif