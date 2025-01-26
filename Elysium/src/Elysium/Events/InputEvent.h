#pragma once
#include "Elysium/Core.h"
#include "SDL3/SDL.h"

namespace Elysium
{
	class ELYSIUM_API InputEvent
	{
	public:
		static void ReadInput();
		static bool GetQuit()
		{
			return s_Quit;
		}
	private:
		static SDL_Event s_Event;
		static bool s_Quit;
	};
}

