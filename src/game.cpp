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
#include "geometry.hpp"
#include "display.hpp"

#include <iostream>
#include <stdexcept>

#include <SDL.h>

imaginary::Game::Game ()
  : display (0),
    isRunning (false)
{
  std::cout << "Initializing Imaginary...\n";

  if (SDL_Init (SDL_INIT_EVERYTHING) < 0)
    {
      throw std::runtime_error ("Could not initialize SDL.");
    }
  std::cout << "  >> Initialized SDL\n";
 
  SDL_Surface* displaySurface = SDL_SetVideoMode (WINDOW_WIDTH, WINDOW_HEIGHT,
    32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption ("Imaginary", "Imaginary");
  if (!displaySurface)
    {
      throw std::runtime_error ("Could not create a window.  "
                                "Is your graphics card supported?");
    }
  display = new imaginary::Display (displaySurface,
    imaginary::Rectangle (0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
  std::cout << "  >> Created window\n";
}

imaginary::Game::~Game ()
{
  std::cout << "Closing Imaginary...\n";
  SDL_Quit ();
  std::cout << "  >> Shutdown SDL\n";
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
      im.Blit (imaginary::Rectangle (10, 14, 42, 46), *display, imaginary::Point
               (128, 128));
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
  SDL_Flip (display->GetSurface ());
}
