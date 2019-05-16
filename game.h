/**
*  @file      game.h
*  @brief     The interface for the main logic used in cpong.
*
*  @author    Evan Elias Young
*  @date      2019-05-14
*  @date      2019-05-15
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#include "pch.h"

// Global Variables
extern const unsigned int SCREEN_WIDTH;
extern const unsigned int SCREEN_HEIGHT;
extern const unsigned char PADDLE_SPEED;
extern const unsigned int PLAYER_X;
extern const unsigned int BOT_X;
extern const unsigned char PADDLE_WIDTH;
extern const unsigned char PADDLE_HEIGHT;
extern const unsigned char BALL_WIDTH;
extern const unsigned char BALL_HEIGHT;
extern const unsigned char BALL_SPEED;
extern const float BOT_SPEED_MOD;
extern const unsigned char MAX_BOUNCE_ANGLE;

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

void init_game();
void tick();
