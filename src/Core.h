//
// Created by tony on 8/26/21.
//

#ifndef SNOWY_CORE_H
#define SNOWY_CORE_H

#include <pch.h>

#ifdef SNOW_ENABLE_ASSERTS
#define SNOW_ASSERT(x, ...) { if (!(x)) { SNOW_ERROR("Assertion failed: {0}", ## __VA_ARGS__); raise(SIGTRAP); } }
#define SNOW_CORE_ASSERT(x, ...) { if (!(x)) { SNOW_CORE_ERROR("Assertion failed: {0}", ## __VA_ARGS__); raise(SIGTRAP); } }
#else
#define SNOW_ASSERT(x, ...)
#define SNOW_CORE_ASSERT(x, ...)
#endif

#endif //SNOWY_CORE_H
