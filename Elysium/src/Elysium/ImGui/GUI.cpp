#include "GUI.h"
#include <imgui.h>
#include "SDL3/SDL.h"

#pragma region OPENGL
#include "Platform/OpenGL/imgui_impl_opengl3.h"
#pragma endregion OPENGL

#include "Platform/OpenGL/imgui_impl_sdl3.h"

namespace Elysium
{
	void GUI::InitGLGui(SDL_Window* window)
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
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

		m_GLContext = SDL_GL_CreateContext(window);
		ImGui_ImplSDL3_InitForOpenGL(window, m_GLContext);
		ImGui_ImplOpenGL3_Init(GLSL_VERSION);
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
#pragma region OPENGL
		ImGui::End();
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
#pragma endregion OPENGL
	}

	GUI::~GUI()
	{
		SDL_GL_DestroyContext(m_GLContext);
	}
}

