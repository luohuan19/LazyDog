
#include <iostream>
#include <LazyDog.h>


class ExampleLayer : public LazyDog::Layer
{
public:
	ExampleLayer()
		: Layer("Example"){}

	void OnUpdate() override
	{
		
	}
	void OnEvent(LazyDog::Event& event) override
	{
		
	}
};

class Sandbox : public LazyDog::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox(){}
};

LazyDog::Application* LazyDog::CreateAppliction()
{
	return new Sandbox();
}