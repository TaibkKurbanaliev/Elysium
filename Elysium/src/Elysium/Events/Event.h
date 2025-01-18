#pragma once

#include "epch.h"
#include "SDL3/SDL.h"
#include "SDL3/SDL_main.h"
#include "SDL3/SDL_events.h"

namespace Elysium
{
	class Event
	{
		Event()
		{
			SDL_Event event;
			SDL_AddEventWatch(SDL_Event)
		}
	};
}


