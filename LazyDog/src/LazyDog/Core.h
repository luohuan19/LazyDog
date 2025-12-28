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

#ifdef LD_ENABLE_ASSERTS
	#define LD_ASSERT(x, ...){if(!(x)){LD_ERROR("Assertion Failed: {0}", __VA_ARGS__);__debugbreak();}}
	#define LD_CORE_ASSERT(x, ...){if(!(x)){LD_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__);__debugbreak();}}
#else
	#define LD_ASSERT(x, ...)
	#define LD_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)