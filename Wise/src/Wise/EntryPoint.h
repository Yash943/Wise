#pragma once

#ifdef WS_PLATFORM_WINDOWS

extern Wise::Application* Wise::CreateApplication();

int main(int argc, char** argv) {

	auto app = Wise::CreateApplication();
	app->Run();
	delete app;
}

#endif