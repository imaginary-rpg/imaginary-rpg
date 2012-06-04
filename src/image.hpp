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

/// @file image.hpp
/// Contains the Image class.

#ifndef IMAGINARY_IMAGE_HPP
#define IMAGINARY_IMAGE_HPP

#include <string>

struct SDL_Surface;

namespace imaginary
{

struct Point;
struct Rectangle;
class Display;


/**
 * A buffer that holds a bitmap.  An Image can blit itself to any other Image or
 * to the window surface in a Display.
 *
 * @version 0.1
 * @author  Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
 * @date    2012-06-03
 * @since   0.1
 *
 * @note This is likely at a lower level than what you need.  Consider using an
 * Animation or a Frame.
 *
 * @todo The width and height fields are probably unneccessary.  Remove them.
 */
class Image
{
  public:
    /**
     * Constructs a new Image object by loading it from a specified path.  All
     * formats that are supported by SDL_image are supported by this class.
     *
     * @author Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date   2012-06-03
     * @since  0.1
     *
     * @param [in] fileName The path to the image file to load.
     */
    Image (std::string fileName);
    /**
     * Destructs an existing Image object and frees any memory associated with
     * it.
     *
     * @author Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date   2012-06-03
     * @since  0.1
     */
    ~Image ();

    /**
     * Returns the width of the Image.
     *
     * @author Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date   2012-06-03
     * @since  0.1
     *
     * @return The width of the bitmap buffer.
     */
    unsigned GetWidth ()  const;
    /**
     * Returns the height of the Image.
     *
     * @author Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date   2012-06-03
     * @since  0.1
     *
     * @return The height of the bitmap buffer.
     */
    unsigned GetHeight () const;

    /**
     * Bitblits a part of this Image to a specific location in the level.  If
     * this location is within the view port of the Display, the Image  will be
     * bitblitted to the backbuffer, to be drawn to the screen at the next
     * flip.  The position of the Image inside the view port will be correct.
     *
     * @author Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date   2012-06-03
     * @since  0.1
     *
     * @param [in] part     The part of this Image to blit.
     * @param [in] d        The Display whose view port to check.
     * @param [in] location The location in the level to draw this Image.
     *
     * @warning You probably don't want to call this method.  Consider using the
     * wrappers Animation and/or Frame.
     */
    void Blit (Rectangle part, Display& d, Point location);
    /**
     * Bitblits a part of this Image to a specific location in another Image.
     *
     * @author Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date   2012-06-03
     * @since  0.1
     *
     * @param [in] part     The part of this Image to blit.
     * @param [in] img      The Image into which to copy this Image.
     * @param [in] location The location in the level to draw this Image.
     *
     * @warning You probably don't want to call this method.  Consider using the
     * wrappers Animation and/or Frame.
     */
    void Blit (Rectangle part, Image& img, Point location);

  private:
    SDL_Surface* surface; ///< The actual buffer containing the bitmap.
    unsigned width;       ///< The width of the bitmap.
    unsigned height;      ///< The height of the bitmap.
};

}

#endif // #ifndef IMAGINARY_IMAGE_HPP
