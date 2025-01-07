#pragma once

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
		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* CreateWindow(const WindowProps& props = WindowProps());
	};
}