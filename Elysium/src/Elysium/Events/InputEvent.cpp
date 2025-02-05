#include "InputEvent.h"
#include <Platform/OpenGL/imgui_impl_sdl3.h>

namespace Elysium
{
	bool Elysium::InputEvent::s_Quit = false;
	SDL_Event Elysium::InputEvent::s_Event;

	void InputEvent::ReadInput()
	{
		while (SDL_PollEvent(&s_Event))
		{
			ImGui_ImplSDL3_ProcessEvent(&s_Event);
			switch (s_Event.type)
			{
			case SDL_EVENT_QUIT:
				s_Quit = true;
				return;
			}
		}
	}
}