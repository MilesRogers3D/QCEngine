#pragma once

#ifdef QC_PLATFORM_WINDOWS
	#ifdef QC_BUILD_DLL
		#define QC_API _declspec(dllexport)
	#else
		#define QC_API _declspec(dllimport)
	#endif
#else
	#error QC Engine currently only supports Windows!
#endif

#ifdef QC_ENABLE_ASSERTS
	#define QC_ASSERT(x, ...) { if(!(x)) { QC_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define QC_CORE_ASSERT(x, ...) { if(!(x)) { QC_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define QC_ASSERT(x, ...);
	#define QC_CORE_ASSERT(x, ...);
#endif

#define BIT(x) (1 << x)