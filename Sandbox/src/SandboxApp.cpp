#include <Trail.h>

class Sandbox : public Trail::Application {//inherits the trail application class that contains the "Run" function
private:

public:	
	Sandbox() {

	}
	~Sandbox() {

	}
};

Trail::Application* Trail::CreateApplication() {//declaration of the function located in dll/Application.h because of the include
	return new Sandbox();
}