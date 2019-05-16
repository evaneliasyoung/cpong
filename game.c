/**
*  @file      game.c
*  @brief     The implementation for the main logic used in cpong.
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

const char COLLIDE_NONE = -1;
const char COLLIDE_WALL = 0;
const char COLLIDE_PLAYER = 1;
const char COLLIDE_BOT = 2;

void init_game()
{
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

  srand(time(0));
  running = true;
  player_score = 0;
  bot_score = 0;

  player_y = floor((SCREEN_HEIGHT - PADDLE_HEIGHT) / 2);
  bot_y = floor((SCREEN_HEIGHT - PADDLE_HEIGHT) / 2);

  ball_reset();
  draw_all();
}

void bot_move()
{
  float goal_mid;
  float bot_mid;
  float bot_move;

  bot_mid = bot_y + PADDLE_HEIGHT / 2;
  if (ball_x + BALL_WIDTH < PLAYER_X || ball_x + BALL_WIDTH > BOT_X)
  { // Move to center-stage
    goal_mid = (SCREEN_HEIGHT - PADDLE_HEIGHT) / 2;
  }
  else
  { // Move to the ball
    goal_mid = ball_y + BALL_HEIGHT / 2;
  }
  if (bot_mid + PADDLE_SPEED > goal_mid && bot_mid - PADDLE_SPEED < goal_mid)
  { // Already in line
    return;
  }

  bot_move = (goal_mid - bot_mid < 0 ? -1 : 1) * PADDLE_SPEED * BOT_SPEED_MOD;

  bot_y = clamp(round((float)bot_y + bot_move), 0, SCREEN_HEIGHT - PADDLE_HEIGHT);
}

void ball_reset()
{
  ball_x = (SCREEN_WIDTH - BALL_WIDTH) / 3;
  ball_y = (SCREEN_HEIGHT - BALL_HEIGHT) / 2;

  vel_x = BALL_SPEED / 1.5;
  vel_y = 0;
}

void ball_move()
{
  ball_x += vel_x;
  ball_y += vel_y;
}

char ball_collide()
{
  float ball_l = ball_x;
  float ball_r = ball_x + BALL_WIDTH;
  float ball_t = ball_y;
  float ball_b = ball_y + BALL_HEIGHT;

  if (ball_l >= PLAYER_X && ball_l <= PLAYER_X + PADDLE_WIDTH)
  { // Player Paddle Zone
    if (ball_b >= player_y && ball_t <= player_y + PADDLE_HEIGHT)
    {
      return COLLIDE_PLAYER;
    }
  }
  if (ball_r >= BOT_X && ball_r <= BOT_X + PADDLE_WIDTH)
  { // Bot Paddle Zone
    if (ball_b >= bot_y && ball_t <= bot_y + PADDLE_HEIGHT)
    {
      return COLLIDE_BOT;
    }
  }
  if (round(ball_t) <= 2 || round(ball_b) >= SCREEN_HEIGHT - 2)
  {
    return COLLIDE_WALL;
  }

  return COLLIDE_NONE;
}

bool ball_side()
{
  return ball_x > floor(SCREEN_WIDTH * 0.47);
}

void ball_physics()
{
  char col = ball_collide();

  if (col != COLLIDE_NONE)
  {
    if (col != COLLIDE_WALL)
    {
      float normalized, angle;
      if (col == COLLIDE_PLAYER)
      {
        float ball_mid = ball_y + BALL_HEIGHT / 2;
        float paddle_mid = (col == COLLIDE_PLAYER ? player_y : bot_y) + PADDLE_HEIGHT / 2;
        float intersect = paddle_mid - ball_mid;
        normalized = intersect / (float)PADDLE_HEIGHT;
        angle = normalized * MAX_BOUNCE_ANGLE;
      }
      else
      {
        normalized = (rand() - ((float)RAND_MAX / 2)) / (float)RAND_MAX;
      }
      angle = normalized * MAX_BOUNCE_ANGLE;
      vel_x = BALL_SPEED * cos(angle / 180.0) * (col == COLLIDE_BOT ? -1 : 1);
      vel_y = BALL_SPEED * sin(angle / 180.0) * -1;
    }
    else
    {
      vel_y *= -1;
    }
  }
  ball_move();

  if (ball_x + BALL_WIDTH < 0)
  {
    ball_reset();
    ++bot_score;
  }
  else if (ball_x > SCREEN_WIDTH)
  {
    ball_reset();
    ++player_score;
  }
}

void tick()
{
  handle_keys(SDL_GetKeyboardState(NULL));

  ball_physics();

  bot_move();
  draw_all();
}
