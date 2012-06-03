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
#include "geometry.hpp"

#include <SDL.h>

imaginary::Display::Display (SDL_Surface* buffer, imaginary::Rectangle viewPort)
  : surface (buffer), viewPort (viewPort)
{}

imaginary::Display::~Display ()
{
  SDL_FreeSurface (surface);
}

imaginary::Rectangle
imaginary::Display::GetViewPort ()
  const
{
  return viewPort;
}

void
imaginary::Display::MoveViewPort (imaginary::Point newLocation)
{
  int width  = viewPort.bottomRight.x - viewPort.topLeft.x;
  int height = viewPort.bottomRight.y - viewPort.topLeft.y;

  viewPort.topLeft = viewPort.bottomRight = newLocation;
  viewPort.bottomRight.x += width;
  viewPort.bottomRight.y += height;
}

SDL_Surface*
imaginary::Display::GetSurface ()
  const
{
  return surface;
}
