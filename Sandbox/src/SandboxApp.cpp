#include "Wise.h"

class Sandbox : public Wise::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
};

Wise::Application* Wise::CreateApplication()
{
	return new Sandbox();
}