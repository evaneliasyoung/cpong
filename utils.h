/**
*  @file      draw.h
*  @brief     The interface for the utils used in cpong.
*
*  @author    Evan Elias Young
*  @date      2019-05-14
*  @date      2019-05-16
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#include "pch.h"

// Global Variables
extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Event e;
extern bool running;
extern unsigned char player_score;
extern unsigned char bot_score;
extern unsigned int player_y;
extern unsigned int bot_y;
extern float ball_x;
extern float ball_y;
extern float vel_x;
extern float vel_y;

int clamp(const int n, const int min, const int max);
float flclamp(const float n, const float min, const float max);
void log_sdl(const char msg[]);
bool init_sdl();
void closing();
void handle_keys(const unsigned char keys[]);
