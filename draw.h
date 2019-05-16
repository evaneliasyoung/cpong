/**
*  @file      draw.h
*  @brief     The interface for the drawing used in cpong.
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

void draw_bg();
void draw_net();
void draw_ball();
void draw_paddle(const unsigned int x, const unsigned int y);
void draw_scan();
void draw_all();
