#pragma once

#ifdef ELYSIUM_WINDOWS

extern Elysium::Application* Elysium::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Elysium::CreateApplication();
	app->Run();
	delete app;
}

#endif // ELYSIUM_WINDOWS
