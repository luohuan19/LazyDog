
#include <iostream>
#include <LazyDog.h>

class Sandbox : public LazyDog::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox(){}
};

LazyDog::Application* LazyDog::CreateAppliction()
{
	return new Sandbox();
}