#pragma once
#include "Elysium/Core.h"
#include "Widgets/Widget.h"
#include "epch.h"
#include "SDL3/SDL.h"

struct ImGuiIO;

namespace Elysium
{
	class ELYSIUM_API GUI
	{
	public:
		void InitGLGui(SDL_Window* window, SDL_GLContext context);
		void Update();
		void Begin();
		void End();
		virtual ~GUI();

	private:
		std::vector<Widget*> m_Widgets;
		ImGuiIO* m_IO = nullptr;
		const char* GLSL_VERSION = "#version 460";
	};
}

