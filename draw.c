/**
*  @file      draw.c
*  @brief     The implementation for the drawing used in cpong.
*
*  @author    Evan Elias Young
*  @date      2019-05-14
*  @date      2019-05-15
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#include "pch.h"
#include "draw.h"

void draw_bg()
{
  SDL_RenderClear(renderer);
}

void draw_rect(unsigned int x, unsigned int y, unsigned int w, unsigned int h)
{
  SDL_Rect r = {x, y, w, h};
  SDL_RenderFillRect(renderer, &r);
}

void draw_segment(unsigned int d, const unsigned int x, const unsigned int y)
{
  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

  if (d & 1)
  {
    draw_rect(x, y, 8, 8);
  }
  if (d & 2)
  {
    draw_rect(x + 8, y, 16, 8);
  }
  if (d & 4)
  {
    draw_rect(x + 24, y, 8, 8);
  }
  if (d & 8)
  {
    draw_rect(x + 24, y + 8, 8, 20);
  }
  if (d & 16)
  {
    draw_rect(x + 24, y + 28, 8, 8);
  }
  if (d & 32)
  {
    draw_rect(x + 24, y + 36, 8, 20);
  }
  if (d & 64)
  {
    draw_rect(x + 24, y + 56, 8, 8);
  }
  if (d & 128)
  {
    draw_rect(x + 8, y + 56, 16, 8);
  }
  if (d & 256)
  {
    draw_rect(x, y + 56, 8, 8);
  }
  if (d & 512)
  {
    draw_rect(x, y + 36, 8, 20);
  }
  if (d & 1024)
  {
    draw_rect(x, y + 28, 8, 8);
  }
  if (d & 2048)
  {
    draw_rect(x, y + 8, 8, 20);
  }
  if (d & 4096)
  {
    draw_rect(x + 8, y + 28, 16, 8);
  }
}

void draw_score(bool isPlayer, const unsigned char score)
{
  unsigned int x = isPlayer ? 217 : 602;
  unsigned int y = 112;
  unsigned char scores[3];
  scores[0] = score % 10;
  scores[1] = (score % 100 - score % 10) / 10;
  scores[2] = (score - score % 100) / 100;

  for (size_t i = 0; i < 3; ++i)
  {
    if (scores[i] == 0 && i > 0)
    {
      continue;
    }

    switch (scores[i])
    {
    case 0:
      draw_segment(4095, x, y);
      break;
    case 1:
      draw_segment(124, x, y);
      break;
    case 2:
      draw_segment(6111, x, y);
      break;
    case 3:
      draw_segment(5631, x, y);
      break;
    case 4:
      draw_segment(7293, x, y);
      break;
    case 5:
      draw_segment(7671, x, y);
      break;
    case 6:
      draw_segment(8183, x, y);
      break;
    case 7:
      draw_segment(127, x, y);
      break;
    case 8:
      draw_segment(8191, x, y);
      break;
    case 9:
      draw_segment(7679, x, y);
      break;
    }
    x -= 48;
  }
}

void draw_net()
{
  SDL_Rect rect = {376, 0, 4, 8};

  for (size_t i = 0; i < 31; ++i)
  {
    rect.y = 88 + (2 * i * 8);
    SDL_RenderFillRect(renderer, &rect);
  }
}

void draw_ball()
{
  SDL_Rect rect = {round(ball_x), round(ball_y), BALL_WIDTH, BALL_HEIGHT};

  SDL_RenderFillRect(renderer, &rect);
}

void draw_paddle(const unsigned int x, const unsigned int y)
{
  SDL_Rect rect = {x, y, PADDLE_WIDTH, PADDLE_HEIGHT};

  SDL_RenderFillRect(renderer, &rect);
}

void draw_scan()
{
  for (size_t i = 0; i < SCREEN_HEIGHT; i += 2)
  {
    SDL_RenderDrawLine(renderer, 0, i, SCREEN_WIDTH, i);
  }
}

void draw_all()
{
  SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF); // Black elements
  draw_bg();                                                // Fill in the background

  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); // White elements
  draw_net();                                               // Fill in the net
  draw_ball();                                              // Fill in the ball
  draw_paddle(PLAYER_X, player_y);                          // Fill in the player paddle
  draw_paddle(BOT_X, bot_y);                                // Fill in the bot paddle
  draw_score(true, player_score);                           // Fill in the player score
  draw_score(false, bot_score);                             // Fill in the bot score

  SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xAA); // 66% elements
  draw_scan();                                              // Draw in the scanlines

  SDL_RenderPresent(renderer);
}
