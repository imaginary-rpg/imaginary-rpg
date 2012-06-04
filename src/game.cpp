/* Imaginary: A Free Software Adventure RPG
 * Copyright (C) 2012, the people listed in the AUTHORS file.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "config.h"
#include "game.hpp"
#include "image.hpp"
#include "display.hpp"

#include <iostream>
#include <stdexcept>

#include <SDL.h>


imaginary::Sdl::Sdl ()
{
  if (SDL_Init (SDL_INIT_EVERYTHING) < 0)
    {
      throw std::runtime_error ("Could not initialize SDL.");
    }
  std::cout << "Initialized SDL\n";
}

imaginary::Sdl::~Sdl ()
{
  SDL_Quit ();
}


imaginary::Game::Game ()
  : sdl (),
    display (WINDOW_WIDTH, WINDOW_HEIGHT, "Imaginary"),
    isRunning (false)
{
}

imaginary::Game::~Game ()
{
}

int
imaginary::Game::Run ()
{
  isRunning = true;
  std::cout << "Starting game...\n";
  std::cout << "  >> To quit, close the window or press enter\n";

  // Hack, to test
  imaginary::Image im ("../res/sprites/char/daedalus_walkcycle.png");

  while (isRunning)
    {
      SDL_Event event;
      while (SDL_PollEvent (&event))
        {
          HandleEvent (&event);
        }
 
      Update ();
      // Hack, to test
      SDL_Rect source = { 10, 14, 42, 46 };
      im.Blit (source, display, 128, 128);
      Render ();
    }

  return 0;
}

void
imaginary::Game::HandleEvent (SDL_Event *event)
{
  switch (event->type)
    {
    case SDL_QUIT:
      isRunning = false;
      break;
    case SDL_KEYUP:
      if (event->key.keysym.sym == SDLK_RETURN)
        {
          isRunning = false;
        }
    }
}

void
imaginary::Game::Update ()
{
}

void
imaginary::Game::Render ()
{
  display.Flip ();
}
