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
#include "geometry.hpp"


imaginary::Point::Point (int x, int y)
  : x (x), y (y)
{}


imaginary::Rectangle::Rectangle (Point topLeft, Point bottomRight)
  : topLeft (topLeft), bottomRight (bottomRight)
{}

imaginary::Rectangle::Rectangle (int x, int y, int width, int height)
  : topLeft (x, y), bottomRight (x + width, y + height)
{}

imaginary::Rectangle::Rectangle (Point topLeft, int width, int height)
  : topLeft (topLeft), bottomRight (topLeft.x + width, topLeft.y + height)
{}
