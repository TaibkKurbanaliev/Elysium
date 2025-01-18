#include "Window.h"
#include "glad/glad.h"
#include "imgui.h"
#include "Platform/OpenGL/imgui_impl_opengl3.h"
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
		SDL_GLContext gl_context = SDL_GL_CreateContext(m_Window);
		ImGui::CreateContext();
		// Setup Dear ImGui style
		ImGui::StyleColorsDark();
		//ImGui::StyleColorsLight();

		// Setup Platform/Renderer backends
		ImGui_ImplSDL3_InitForOpenGL(m_Window, gl_context);
		ImGui_ImplOpenGL3_Init("#version 410");
	}

	Window::~Window()
	{
		SDL_DestroyWindow(m_Window);
	}

	void Window::OnUpdate()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(1.0f, 0.0f, 1.0f, 1.0f);

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplSDL3_NewFrame();
		ImGui::NewFrame();
		ImGui::ShowDemoWindow();
		static float f = 0.0f;
		static int counter = 0;

		ImGui::Begin("Hello, world!");                          

		ImGui::Text("This is some useful text.");              

		ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            

		if (ImGui::Button("Button"))                         
			counter++;
		ImGui::SameLine();
		ImGui::Text("counter = %d", counter);

		ImGui::End();
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

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