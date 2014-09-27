#pragma once

// Use VLD to check memory leak
// #define USE_VLD
#ifdef USE_VLD
	#include "vld.h"
#endif

#include <stdio.h>
#include <Windows.h>

#include "macros.h"
#include "error_code.h"
