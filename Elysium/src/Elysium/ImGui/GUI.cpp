#include "glad/glad.h"
#include "GUI.h"
#include <imgui.h>
#include "SDL3/SDL.h"

#pragma region OPENGL
#include "Platform/OpenGL/imgui_impl_opengl3.h"
#pragma endregion OPENGL

#include "Platform/OpenGL/imgui_impl_sdl3.h"

namespace Elysium
{
	void GUI::InitGLGui(SDL_Window* window, SDL_GLContext context)
	{
		EL_CORE_INFO("Initialize GUI");
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO io = ImGui::GetIO(); (void)io;
		m_IO = &io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
		//io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoTaskBarIcons;
		//io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoMerge;

		//float fontSize = 18.0f;// *2.0f;
		//io.Fonts->AddFontFromFileTTF("assets/fonts/opensans/OpenSans-Bold.ttf", fontSize);
		//io.FontDefault = io.Fonts->AddFontFromFileTTF("assets/fonts/opensans/OpenSans-Regular.ttf", fontSize);

		// Setup Dear ImGui style
		ImGui::StyleColorsDark();
		//ImGui::StyleColorsClassic();

		ImGuiStyle& style = ImGui::GetStyle();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}

		ImGui::StyleColorsDark();

		ImGui_ImplSDL3_InitForOpenGL(window, context);
		ImGui_ImplOpenGL3_Init(GLSL_VERSION);

		EL_CORE_INFO("GUI was initialized");
	}

	void GUI::Update()
	{
		Begin();
		// Temp
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
		// Temp

		End();
	}

	void GUI::Begin()
	{
#pragma region OPENGL
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplSDL3_NewFrame();
		ImGui::NewFrame();
#pragma endregion OPENGL
	}

	void GUI::End()
	{
		ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
#pragma region OPENGL
		ImGui::End();
		ImGui::Render();
		glViewport(0, 0, (int)m_IO->DisplaySize.x, (int)m_IO->DisplaySize.y);
		glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		if (m_IO->ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			SDL_Window* backup_current_window = SDL_GL_GetCurrentWindow();
			SDL_GLContext backup_current_context = SDL_GL_GetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			SDL_GL_MakeCurrent(backup_current_window, backup_current_context);
		}
#pragma endregion OPENGL
	}

	GUI::~GUI()
	{
		m_IO = nullptr;
	}
}

