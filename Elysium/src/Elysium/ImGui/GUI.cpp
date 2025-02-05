#include "glad/glad.h"
#include "GUI.h"
#include <imgui.h>
#include "SDL3/SDL.h"

#pragma region OPENGL
#include "Platform/OpenGL/imgui_impl_opengl3.h"
#pragma endregion OPENGL

#include "Platform/OpenGL/imgui_impl_sdl3.h"
#include <imgui_internal.h>

namespace Elysium
{
	void GUI::InitGLGui(SDL_Window* window, SDL_GLContext context)
	{
		EL_CORE_INFO("Initialize GUI");
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
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

	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	void GUI::Update()
	{
		Begin();
		// Temp
		SetupDockingLayout();
		// Temp

		CreateInspector();
		CreateSceneView();
		Hierarchy();
		CreateExplorer();

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

	void GUI::SetupDockingLayout()
	{
		ImGuiID dockspace_id = ImGui::GetMainViewport()->ID;
		ImGui::DockSpaceOverViewport(dockspace_id, ImGui::GetMainViewport(), ImGuiDockNodeFlags_None);
		static bool firstTime = true;

		if (firstTime)
		{
			firstTime = !firstTime;
			ImGui::DockBuilderRemoveNode(dockspace_id);
			ImGui::DockBuilderAddNode(dockspace_id, ImGuiDockNodeFlags_DockSpace);
			ImGui::DockBuilderSetNodeSize(dockspace_id, ImGui::GetMainViewport()->Size);

			ImGuiID dock_main_id = dockspace_id;
			ImGuiID dock_left_id = ImGui::DockBuilderSplitNode(dock_main_id, ImGuiDir_Left, 0.2f, nullptr, &dock_main_id);
			ImGuiID dock_right_id = ImGui::DockBuilderSplitNode(dock_main_id, ImGuiDir_Right, 0.2f, nullptr, &dock_main_id);
			ImGuiID dock_bottom_id = ImGui::DockBuilderSplitNode(dock_main_id, ImGuiDir_Down, 0.25f, nullptr, &dock_main_id);

			ImGui::DockBuilderDockWindow("Scene View", dock_main_id);
			ImGui::DockBuilderDockWindow("Inspector", dock_right_id);
			ImGui::DockBuilderDockWindow("Explorer", dock_bottom_id);
			ImGui::DockBuilderDockWindow("Hierarchy", dock_left_id);

			ImGui::DockBuilderFinish(dockspace_id);
		}
	}

	void GUI::CreateSceneView()
	{
		ImGui::Begin("Scene View");
		ImGui::Text("This is the Scene View.");
		ImGui::End();

	}
	void GUI::CreateInspector()
	{
		ImGui::Begin("Inspector");
		ImGui::Text("This is the Inspector.");
		ImGui::End();
	}
	void GUI::Hierarchy()
	{
		ImGui::Begin("Hierarchy");
		ImGui::Text("This is the Hierarchy.");
		ImGui::End();
	}

	void GUI::CreateExplorer()
	{
		ImGui::Begin("Explorer");
		ImGui::Text("This is the Explorer.");
		ImGui::End();
	}

	GUI::~GUI()
	{
		m_IO = nullptr;
	}
}

