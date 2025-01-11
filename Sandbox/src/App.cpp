#include <Elysium.h>

class Sandbox : public Elysium::Application
{
public:
	Sandbox();
	~Sandbox();

private:

};

Elysium::Application* Elysium::CreateApplication()
{
	return new Sandbox();
}

Sandbox::Sandbox()
{
}

Sandbox::~Sandbox()
{
}
