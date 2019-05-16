/**
*  @file      pch.h
*  @brief     The all-includer file.
*
*  @author    Evan Elias Young
*  @date      2019-05-14
*  @date      2019-05-16
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef CPONG_PCH_H_
#define CPONG_PCH_H_

#define SCREEN_WIDTH 800u
#define SCREEN_HEIGHT 600u
#define PLAYER_X 121u
#define BOT_X 633u
#define PADDLE_WIDTH 8u
#define PADDLE_HEIGHT 30u
#define PADDLE_SPEED 3
#define BALL_WIDTH 8u
#define BALL_HEIGHT 8u
#define BALL_SPEED 5
#define MAX_BOUNCE_ANGLE 130u
#define BOT_SPEED_MOD 0.6f

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <time.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <SDL2/SDL.h>

#endif // CPONG_PCH_H_
