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
#include "image.hpp"
#include "display.hpp"

#include "SDL_image.h"

#include <string>
#include <stdexcept>

imaginary::Image::Image (std::string fileName)
  : surface (0)
{
  SDL_Surface* temp = 0;
 
  temp = IMG_Load (fileName.c_str ());
  if (temp == 0)
    throw std::runtime_error ("Could not open file");
 
  surface = SDL_DisplayFormatAlpha (temp);
  SDL_FreeSurface (temp);
}

imaginary::Image::~Image ()
{
  SDL_FreeSurface (surface);
}

unsigned
imaginary::Image::GetWidth ()
  const
{
  return surface->w;
}

unsigned
imaginary::Image::GetHeight ()
  const
{
  return surface->h;
}


void
imaginary::Image::Blit (SDL_Rect          part,
                        imaginary::Image& img,
                        int               x,
                        int               y)
{
  SDL_Rect destination;
  destination.x = x;
  destination.y = y;
  destination.w = part.w;
  destination.h = part.h;
 
  SDL_BlitSurface (surface, &part, img.surface, &destination);
}

void
imaginary::Image::Blit (SDL_Rect            part,
                        imaginary::Display& d,
                        int                 x,
                        int                 y)
{
  SDL_Rect viewPort = d.GetViewPort ();

  if (x > viewPort.x + viewPort.w ||
      y > viewPort.y + viewPort.h ||
      x + part.w < viewPort.x     ||
      y + part.h < viewPort.y)
    {
      // Outside the screen, don't blit.
      return;
    }

  SDL_Rect destination;
  destination.x = x - viewPort.x;
  destination.y = y - viewPort.y;
  destination.w = part.w;
  destination.h = part.h;
 
  SDL_BlitSurface (surface, &part, d.GetSurface (), &destination);
}
