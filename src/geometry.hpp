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

/// @file geometry.hpp
/// Contains the Point and Rectangle classes.

#ifndef IMAGINARY_GEOMETRY_HPP
#define IMAGINARY_GEOMETRY_HPP

namespace imaginary
{


/**
 * A point in the X-Y plane.
 *
 * @version 0.1
 * @author  Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
 * @date    2012-06-03
 * @since   0.1
 */
struct Point
{
  public:
    /**
     * Constructs a new Point object.
     *
     * @author Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date   2012-06-03
     * @since  0.1
     *
     * @param [in] x The x-coordinate.
     * @param [in] y The y-coordinate.
     */
    Point (int x, int y);

    int x; ///< The x-coordinate relative to the origin.
    int y; ///< The y-coordinate relative to the origin.
};


/**
 * A rectangle, defined by its upper left corner and its lower right corner.
 * This class does not check that the lower right corner has greater x- and
 * y-coordinates than the upper left corner.
 *
 * @version 0.1
 * @author  Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
 * @date    2012-06-03
 * @since   0.1
 */
struct Rectangle
{
  public:
    /**
     * Constructs a new Rectangle object from two points.
     *
     * @author Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date   2012-06-03
     * @since  0.1
     *
     * @param [in] topLeft     The upper left corner.
     * @param [in] bottomRight The lower right corner.
     */
    Rectangle (Point topLeft, Point bottomRight);
    /**
     * Constructs a new Rectangle object from a point and a width and height.
     *
     * @author Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date   2012-06-03
     * @since  0.1
     *
     * @param [in] x      The x-coordinate of the lower right corner.
     * @param [in] y      The y-coordinate of the upper left corner.
     * @param [in] width  The width of the rectangle.
     * @param [in] height The height of the rectangle.
     */
    Rectangle (int x, int y, int width, int height);
    /**
     * Constructs a new Rectangle object from a point and a width and height.
     *
     * @author Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date   2012-06-03
     * @since  0.1
     *
     * @param [in] topLeft The upper left corner.
     * @param [in] width   The width of the rectangle.
     * @param [in] height  The height of the rectangle.
     */
    Rectangle (Point topLeft, int width, int height);

    Point topLeft;     ///< The upper left corner.
    Point bottomRight; ///< The lower right corner.
};


}

#endif // #ifndef IMAGINARY_GEOMETRY_HPP
