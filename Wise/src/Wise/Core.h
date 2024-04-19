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

#define BIT(x) (1<<x)