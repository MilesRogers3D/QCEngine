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

#define BIT(x) (1 << x)