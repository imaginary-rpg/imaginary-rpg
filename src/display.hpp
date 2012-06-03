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

#ifndef IMAGINARY_DISPLAY_HPP
#define IMAGINARY_DISPLAY_HPP

#include "geometry.hpp"

struct SDL_Surface;

namespace imaginary
{

struct Rectangle;
struct Point;

class Display
{
  public:
    Display (SDL_Surface* buffer, Rectangle viewPort);
    ~Display ();

    Rectangle GetViewPort () const;
    void MoveViewPort (Point newLocation);

    SDL_Surface* GetSurface () const;

  private:
    SDL_Surface* surface;
    Rectangle    viewPort;
};

}

#endif // #ifndef IMAGINARY_DISPLAY_HPP
