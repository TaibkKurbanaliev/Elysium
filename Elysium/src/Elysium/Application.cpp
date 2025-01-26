#include "Application.h"
#include "Events/InputEvent.h"

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
		bool isRunning = true;

		while (isRunning)
		{
			InputEvent::ReadInput();
			isRunning = !InputEvent::GetQuit();

			m_Window->OnUpdate();
			;
		}
	}
}
