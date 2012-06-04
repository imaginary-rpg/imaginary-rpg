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
#include "geometry.hpp"
#include "display.hpp"

#include "SDL_image.h"

#include <string>
#include <stdexcept>

imaginary::Image::Image (std::string fileName)
  : surface (0), width (0), height (0)
{
  SDL_Surface* temp = 0;
 
  temp = IMG_Load (fileName.c_str ());
  if (temp == 0)
    throw std::runtime_error ("Could not open file");
 
  surface = SDL_DisplayFormatAlpha (temp);
  SDL_FreeSurface (temp);

  width = surface->w;
  height = surface->h;
}

imaginary::Image::~Image ()
{
  SDL_FreeSurface (surface);
}

unsigned
imaginary::Image::GetWidth ()
  const
{
  return width;
}

unsigned
imaginary::Image::GetHeight ()
  const
{
  return height;
}


void
imaginary::Image::Blit (imaginary::Rectangle part,
                        imaginary::Image&    img,
                        imaginary::Point     location)
{
  SDL_Rect source;
  source.x = part.topLeft.x;
  source.y = part.topLeft.y;
  source.w = part.bottomRight.x - part.topLeft.x;
  source.h = part.bottomRight.y - part.topLeft.y;

  SDL_Rect destination;
  destination.x = location.x;
  destination.y = location.y;
 
  SDL_BlitSurface (surface, &source, img.surface, &destination);
}

void
imaginary::Image::Blit (imaginary::Rectangle part,
                        imaginary::Display&  d,
                        imaginary::Point     location)
{
  SDL_Rect source;
  source.x = part.topLeft.x;
  source.y = part.topLeft.y;
  source.w = part.bottomRight.x - part.topLeft.x;
  source.h = part.bottomRight.y - part.topLeft.y;

  if (location.x > d.GetViewPort ().x + d.GetViewPort ().w ||
      location.y > d.GetViewPort ().y + d.GetViewPort ().h ||
      location.x + source.w < d.GetViewPort ().x           ||
      location.y + source.h < d.GetViewPort ().y)
    {
      // Outside the screen, don't blit.
      return;
    }

  SDL_Rect destination;
  destination.x = location.x - d.GetViewPort ().x;
  destination.y = location.y - d.GetViewPort ().y;
 
  SDL_BlitSurface (surface, &source, d.GetSurface (), &destination);
}
