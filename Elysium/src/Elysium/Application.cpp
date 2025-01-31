#include "Application.h"
#include "Events/InputEvent.h"

namespace Elysium
{
	Application::Application()
	{
		Log::Init();

		EL_CORE_INFO("Create Application...");

		m_Window = std::make_unique<Window>();
		assert(m_Window);

		m_GUI = std::make_unique<GUI>();
		assert(m_GUI);
		m_GUI->InitGLGui(m_Window->GetWindow(), m_Window->GetGLContext());

		EL_CORE_INFO("Application was created");
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
