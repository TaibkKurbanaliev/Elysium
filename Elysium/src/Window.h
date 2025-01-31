#pragma once

#include "SDL3/SDL.h"
#include "epch.h"
#include "Elysium/Core.h"
#include "Elysium/ImGui/GUI.h"

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

		virtual void Update();

		virtual unsigned int GetWidth() const;
		virtual unsigned int GetHeight() const;

		virtual void SetVSync(bool enabled);
		virtual bool IsVSync() const;
		virtual SDL_Window* GetWindow() const { return m_Window; }
		virtual SDL_GLContext GetGLContext() const{ return m_Context; }
		Window(const WindowProps& props = WindowProps());
	private:
		SDL_Window* m_Window = nullptr;
		SDL_GLContext m_Context;
	};
}