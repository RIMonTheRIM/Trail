#include <Trail.h>

class ExampleLayer : public Trail::Layer {
public:
	ExampleLayer() : Layer("Example") {

	}
	void OnUpdate() override {
	}
	void OnEvent(Trail::Event& event) override {
		TRL_TRACE("{0}", event.GetName());
	}
};




class Sandbox : public Trail::Application {//inherits the trail application class that contains the "Run" function
private:

public:	
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Trail::ImGuiLayer());
	}
	~Sandbox() {

	}
};

Trail::Application* Trail::CreateApplication() {//declaration of the function located in dll/Application.h because of the include
	return new Sandbox();
}