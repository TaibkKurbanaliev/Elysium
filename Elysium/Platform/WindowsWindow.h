#pragma once

#include "Window.h"

namespace Elysium
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;
		unsigned int GetWidth() const override { return m_Props->Width; }
		unsigned int GetHeight() const override { return m_Props->Height; }

		bool IsVSync() const override { return m_Props->VSync; }
		void SetVSync(bool enabled) override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void ShutDown();
	private:
		std::unique_ptr<WindowProps> m_Props;
	public:

	};
}


