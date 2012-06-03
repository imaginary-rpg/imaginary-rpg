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

#include <iostream>
#include <stdexcept>

#include <SDL.h>

imaginary::Game::Game ()
  : displaySurface (0),
    isRunning (false)
{
  std::cout << "Initializing Imaginary...\n";

  if (SDL_Init (SDL_INIT_EVERYTHING) < 0)
    {
      throw std::runtime_error ("Could not initialize SDL.");
    }
  std::cout << "  >> Initialized SDL\n";
 
  displaySurface = SDL_SetVideoMode (640, 480, 32,
                                     SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (!displaySurface)
    {
      throw std::runtime_error ("Could not create a window.  "
                                "Is your graphics card supported?");
    }
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
  std::cout << " >> To quit, close the window\n";

  while (isRunning)
    {
      SDL_Event event;
      while (SDL_PollEvent (&event))
        {
          HandleEvent (&event);
        }
 
      Update ();
      Render ();
    }

  return 0;
}

void
imaginary::Game::HandleEvent (SDL_Event *event)
{
  if (event->type == SDL_QUIT)
    {
      isRunning = false;
    }
}

void
imaginary::Game::Update ()
{
}

void
imaginary::Game::Render ()
{
}
