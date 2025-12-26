#pragma once

#ifdef LD_PLATFORM_WINDOWS
	#ifdef LD_BUILD_DLL
		#define LazyDog_API __declspec(dllexport)
	#else
		#define LazyDog_API __declspec(dllimport)
	#endif
#else
	#error LazyDog only support Windows!
#endif

