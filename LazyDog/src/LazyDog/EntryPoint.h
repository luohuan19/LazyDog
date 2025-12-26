#pragma once

#ifdef LD_PLATFORM_WINDOWS

extern LazyDog::Application* LazyDog::CreateAppliction();

int main(int argc, char** argv)
{
	std::cout<<"LazyDog Engine!"<<std::endl;
	auto app = LazyDog::CreateAppliction();
	app->Run();
	delete app;
}

#endif