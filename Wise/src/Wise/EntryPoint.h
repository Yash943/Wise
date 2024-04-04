#pragma once

#ifdef WS_PLATFORM_WINDOWS

extern Wise::Application* Wise::CreateApplication();

int main(int argc, char** argv)
{
	Wise::Log::Init();
	WS_CORE_WARN("Initalized Log!");
	int a = 5;
	WS_INFO("Hello Var = {0}", a);
	auto app = Wise::CreateApplication();
	app->Run();
	delete app;
}

#endif