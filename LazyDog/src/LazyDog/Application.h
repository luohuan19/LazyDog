#pragma once

#include "Core.h"

namespace LazyDog {
	
	class LazyDog_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateAppliction();
}
