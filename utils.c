/**
*  @file      utils.c
*  @brief     The implementation for the utils used in cpong.
*
*  @author    Evan Elias Young
*  @date      2019-05-14
*  @date      2019-05-16
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#include "pch.h"
#include "utils.h"

int clamp(const int n, const int min, const int max)
{
  return n < min ? min : n > max ? max : n;
}

void log_sdl(const char msg[])
{
  printf("%s Error: %s\n", msg, SDL_GetError());
}

bool init_sdl()
{
  bool success = true;

  if (success)
  {
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      log_sdl("InitVideo");
      success = false;
    }
  }
  if (success)
  {
    window = SDL_CreateWindow("CPong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
      log_sdl("CreateWindow");
      success = false;
    }
  }
  if (success)
  {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
      log_sdl("CreateRenderer");
      success = false;
    }
  }

  return success;
}

void closing()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  renderer = NULL;
  window = NULL;
}

void handle_keys(const unsigned char keys[])
{
  if (keys[SDL_SCANCODE_UP] || keys[SDL_SCANCODE_W])
  {
    player_y = clamp(player_y - PADDLE_SPEED, 0, SCREEN_HEIGHT - PADDLE_HEIGHT);
  }
  if (keys[SDL_SCANCODE_DOWN] || keys[SDL_SCANCODE_S])
  {
    player_y = clamp(player_y + PADDLE_SPEED, 0, SCREEN_HEIGHT - PADDLE_HEIGHT);
  }
}
