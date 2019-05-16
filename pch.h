/**
*  @file      pch.h
*  @brief     The all-includer file.
*
*  @author    Evan Elias Young
*  @date      2019-05-14
*  @date      2019-05-14
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef CPONG_PCH_H_
#define CPONG_PCH_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <SDL2/SDL.h>

#endif // CPONG_PCH_H_
