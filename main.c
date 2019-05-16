/**
*  @file      main.cpp
*  @brief     The main entry point for cpong
*
*  @author    Evan Elias Young
*  @date      2019-05-14
*  @date      2019-05-15
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#include "pch.h"
#include "utils.h"
#include "draw.h"
#include "game.h"

// Global Variables
const unsigned int SCREEN_WIDTH = 800;      // The screen width
const unsigned int SCREEN_HEIGHT = 600;     // The screen height
const unsigned char PADDLE_SPEED = 3;       // The maximum pixels/second of a paddle
const unsigned int PLAYER_X = 121;          // The player's x-coordinate
const unsigned int BOT_X = 633;             // The bot's x-coordinate
const unsigned char PADDLE_WIDTH = 8;       // The paddle's width
const unsigned char PADDLE_HEIGHT = 30;     // The paddle's height
const unsigned char BALL_WIDTH = 8;         // The ball's width
const unsigned char BALL_HEIGHT = 8;        // The ball's height
const unsigned char BALL_SPEED = 5;         // The ball's maximum velocity
const float BOT_SPEED_MOD = 0.6;            // The bot's speed multiplier (b/c it would always win otherwise)
const unsigned char MAX_BOUNCE_ANGLE = 130; // The maximum angle of the ball
SDL_Window *window = NULL;                  // The actual display window
SDL_Renderer *renderer = NULL;              // The renderer
SDL_Event e;                                // Any event
bool running = true;                        // Whether or not the game is running
unsigned char player_score = 0;             // The player's current score
unsigned char bot_score = 0;                // The bot's current score
unsigned int player_y = 0;                  // The player's y-coordinate
unsigned int bot_y = 0;                     // The bot's y-coordinate
float ball_x = 0;                           // The ball's x-coordinate
float ball_y = 0;                           // The ball's y-coordinate
float vel_x = 0;                            // The ball's x-velocity
float vel_y = 0;                            // The ball's y-velocity

int main(int argc, char *argv[])
{
  if (init_sdl())
  {
    init_game();
    while (running)
    {
      while (SDL_PollEvent(&e) != 0)
      {
        if (e.type == SDL_QUIT)
        {
          running = false;
        }
      }

      tick();
    }
  }

  return 0;
}
