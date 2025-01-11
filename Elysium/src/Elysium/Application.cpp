#include "Application.h"

namespace Elysium
{
	Application::Application()
	{
		m_Window = std::make_unique<Window>(*Window::CreateWindow());
	}
	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (true)
		{
			;
		}
	}
}
