#pragma once

#ifdef ELYSIUM_WINDOWS
	#ifdef ELYSIUM_BUILD_DLL
		#define ELYSIUM_API __declspec(dllexport)
	#else
		#define ELYSIUM_API __declspec(dllimport)
	#endif // ELYSIUM_BUILD_DLL
#endif // ELYSIUM_WINDOWS
