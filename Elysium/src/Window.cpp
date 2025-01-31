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
		EL_CORE_INFO("Initialize Window...");
		assert(SDL_Init(SDL_INIT_VIDEO) != 0);

		m_Window = SDL_CreateWindow(props.Title.c_str(),
			props.Width,
			props.Height,
			SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
		assert(m_Window);
		SDL_SetWindowMouseRect(m_Window, NULL);

#pragma region OPENGL
		EL_CORE_INFO("Initialize OpenGL...");
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		m_Context = SDL_GL_CreateContext(m_Window);
		assert(m_Context);
		assert(gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress));

		glEnable(GL_DEPTH_TEST);
		SDL_GL_MakeCurrent(m_Window, m_Context);
		SDL_GL_SetSwapInterval(1); 
		SDL_ShowWindow(m_Window);
		EL_CORE_INFO("Successfully");
#pragma endregion OPENGL

		EL_CORE_INFO("Window initialization was successfully");
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
}