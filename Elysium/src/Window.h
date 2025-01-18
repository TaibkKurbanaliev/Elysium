#pragma once

#include "SDL3/SDL.h"
#include "Elysium/Core.h"
#include "epch.h"

namespace Elysium
{	
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		bool VSync;

		WindowProps(const std::string& title = "Elysium Engine",
					unsigned int width = 1280,
					unsigned int height = 720,
					bool vsync = false)
			: Title(title), Width(width), Height(height), VSync(vsync)
		{
		}
	};

	class ELYSIUM_API Window
	{
	public:
		virtual ~Window();

		virtual void OnUpdate();

		virtual unsigned int GetWidth() const;
		virtual unsigned int GetHeight() const;

		virtual void SetVSync(bool enabled);
		virtual bool IsVSync() const;

		static Window* CreateWindow(const WindowProps& props = WindowProps());
	private:
		Window(const WindowProps& props);
		SDL_Window* m_Window = nullptr;
	};
}