#pragma once
#include "Elysium/Core.h"
#include "Widgets/Widget.h"
#include "epch.h"
#include "SDL3/SDL.h"

namespace Elysium
{
	class ELYSIUM_API GUI
	{
	public:
		void InitGLGui(SDL_Window* window);
		void Update();
		void Begin();
		void End();
		virtual ~GUI();

	private:
		std::vector<Widget*> m_Widgets;
		SDL_GLContext m_GLContext;
		const char* GLSL_VERSION = "#version 460";
	};
}

