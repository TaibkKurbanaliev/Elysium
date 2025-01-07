#include "Elysium/Application.h"

class Sandbox : public Elysium::Application
{
public:
	Sandbox();
	~Sandbox();

private:

};

Sandbox::Sandbox()
{
}

Sandbox::~Sandbox()
{
}

void main() 
{
	Sandbox* app = new Sandbox();

	app->Run();
}