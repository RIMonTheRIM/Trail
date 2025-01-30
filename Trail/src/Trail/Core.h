#pragma once

//this if def is here to define TRL_API to help us not have to think about writing __declspec(dllexport) or __declspec(dllimport)
//if we're in the dll, we export, if we're not in the dll we import
#ifdef TRL_PLATFORM_WINDOWS
	#ifdef TRL_BUILD_DLL
		#define TRL_API __declspec(dllexport)
	#else
		#define TRL_API	__declspec(dllimport)
	#endif
#else
	#error Trail only supports windows
#endif

#define BIT(x) (1 << x)