#include "Window.h"

namespace Elysium
{
	Window::Window(const WindowProps& props)
	{
		m_Window = SDL_CreateWindow(props.Title.c_str(), 
									props.Width, 
									props.Height, 
									SDL_WINDOW_RESIZABLE);
	}

	Window::~Window()
	{
		SDL_DestroyWindow(m_Window);
	}

	void Window::OnUpdate()
	{
	}
	unsigned int Window::GetWidth() const
	{
		return 0;
	}
	unsigned int Window::GetHeight() const
	{
		return 0;
	}
	void Window::SetVSync(bool enabled)
	{
	}
	bool Window::IsVSync() const
	{
		return false;
	}
	Window* Elysium::Window::CreateWindow(const WindowProps& props)
	{
		return new Window(props);
	}
}