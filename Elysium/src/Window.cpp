#include "Window.h"
#include "glad/glad.h"
#include "imgui.h"

#pragma region OPENGL
#include "Platform/OpenGL/imgui_impl_opengl3.h"
#pragma endregion OPENGL

#include "Platform/OpenGL/imgui_impl_sdl3.h"

namespace Elysium
{
	Window::Window(const WindowProps& props)
	{
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			;
		}

		m_Window = SDL_CreateWindow(props.Title.c_str(),
			props.Width,
			props.Height,
			SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
		SDL_SetWindowMouseRect(m_Window, NULL);

#pragma region OPENGL
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		if (!SDL_GL_CreateContext(m_Window))
		{
		}

		if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
		{
		}

		glEnable(GL_DEPTH_TEST);
#pragma endregion OPENGL
	}

	Window::~Window()
	{
		SDL_DestroyWindow(m_Window);
	}

	void Window::Update()
	{
		/*glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(1.0f, 0.0f, 1.0f, 1.0f);*/

		SDL_GL_SwapWindow(m_Window);
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