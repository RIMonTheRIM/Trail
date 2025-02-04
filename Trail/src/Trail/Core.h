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


#ifdef TRL_ENABLE_ASSERTS
	#define TRL_ASSERT(x, ...) { if(!(x)) {TRL_ERROR("Assertion failed: {0}", __VA_ARGS__);__debugbreak();} }
	#define TRL_CORE_ASSERT(x, ...) { if(!(x)) {TRL_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__);__debugbreak();} }
#else
	#define  TRL_ASSERT(x, ...)
	#define  TRL_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

