#include "Application.h"
#include "Events/InputEvent.h"

namespace Elysium
{
	Application::Application()
	{
		m_Window.reset(m_Window->CreateWindow());
		m_GUI = std::make_unique<GUI>();
		m_GUI->InitGLGui(m_Window->GetWindow());
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

			m_GUI->Update();
			m_Window->Update();
		}
	}
}
