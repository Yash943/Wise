#pragma once

#ifdef WS_PLATFORM_WINDOWS
	#ifdef WS_BUILD_DLL
		#define WISE_API __declspec(dllexport)
	#else
		#define WISE_API __declspec(dllimport)
	#endif
#else
	#error Wise only support Windows!
#endif

#ifdef WS_DEBUG
	#define WS_ENABLE_ASSERTS
#endif

#ifdef WS_ENABLE_ASSERTS
	#define WS_ASSERT(x, ...) { if(!(x)){WS_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define WS_CORE_ASSERT(x, ...) { if(!(x)){WS_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define WS_ASSERT(x, ...)
	#define WS_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1<<x)

#define WS_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)