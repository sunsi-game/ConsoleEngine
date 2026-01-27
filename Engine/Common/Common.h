#pragma once

#define ENGINE_BUILD_DLL 1

#if _WIN64
#define DLLEXPORT   __declspec( dllexport )
#else
#define DLLIMPORT   __declspec( dllimport )
#endif

// ENGINE_BUILD_DLL이 선언되어 있는지에 따라 분기.
#if ENGINE_BUILD_DLL
#define WANTED_API DLLEXPORT
#else
#define WANTED_API DLLIMPORT
#endif