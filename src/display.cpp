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
#include "display.hpp"

#include <SDL.h>

#include <string>
#include <stdexcept>

imaginary::Display::Display (SDL_Rect viewPort,
                             std::string caption)
  : surface (SDL_SetVideoMode (viewPort.w, viewPort.h, 32,
                               SDL_HWSURFACE | SDL_DOUBLEBUF)),
    viewPort (viewPort)
{
  if (!surface)
    {
      throw std::runtime_error ("Could not create a window.  "
                                "Is your graphics card supported?");
    }
  SDL_WM_SetCaption (caption.c_str (), caption.c_str ());
}

imaginary::Display::~Display ()
{
  SDL_FreeSurface (surface);
}

SDL_Rect
imaginary::Display::GetViewPort ()
  const
{
  return viewPort;
}

void
imaginary::Display::MoveViewPort (int x, int y)
{

  viewPort.x = x;
  viewPort.y = y;
}

SDL_Surface*
imaginary::Display::GetSurface ()
  const
{
  return surface;
}
