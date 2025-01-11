#pragma once
#include "Core.h"
#include "epch.h"
#include <Window.h>

namespace Elysium
{
	class ELYSIUM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
	};

	Application* CreateApplication();
}


