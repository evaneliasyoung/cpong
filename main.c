/**
*  @file      main.cpp
*  @brief     The main entry point for cpong
*
*  @author    Evan Elias Young
*  @date      2019-05-14
*  @date      2019-05-16
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#include "pch.h"
#include "utils.h"
#include "draw.h"
#include "game.h"

// Global Variables
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
  closing();

  return 0;
}
