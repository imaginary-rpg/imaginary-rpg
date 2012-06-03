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

#ifndef IMAGINARY_IMAGE_HPP
#define IMAGINARY_IMAGE_HPP

#include <string>

struct SDL_Surface;

namespace imaginary
{

struct Point;
struct Rectangle;
class Display;

class Image
{
  public:
    Image (std::string fileName);
    ~Image ();

    unsigned GetWidth ()  const;
    unsigned GetHeight () const;

    void Blit (Rectangle part, Display& d, Point location);
    void Blit (Rectangle part, Image& img, Point location);

  private:
    SDL_Surface* surface;
    unsigned width;
    unsigned height;
};

}

#endif // #ifndef IMAGINARY_IMAGE_HPP
