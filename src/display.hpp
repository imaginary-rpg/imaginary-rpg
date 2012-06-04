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

/// @file display.hpp
/// Contains the Display class.

#ifndef IMAGINARY_DISPLAY_HPP
#define IMAGINARY_DISPLAY_HPP

#include <SDL.h>
#include <string>

struct SDL_Surface;
struct SDL_Rect;

namespace imaginary
{


/**
 * The viewport that is drawn into the window.  This class manages the display
 * surface of the window from after its creation (when this class receives it)
 * until the destruction of the window.  The viewport can be moved around the
 * level, but its size cannot be changed.
 *
 * @version 0.1
 * @author  Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
 * @date    2012-06-03
 * @since   0.1
 */
class Display
{
    friend class Image; // So Image can draw itself to the screen.
  public:
    /**
     * Constructs a new Display object, making a window with a specified width,
     * height, and caption.
     *
     * @author Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date   2012-06-03
     * @since  0.1
     *
     * @param [in] width   The width of the window.
     * @param [in] height  The height of the window.
     * @param [in] caption The caption for the window.
     */
    Display (unsigned width, unsigned height, std::string caption);
    /**
     * Destructs an existing Display object.  This frees the SDL surface.
     *
     * @author Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date   2012-06-03
     * @since  0.1
     */
    ~Display ();

    /**
     * Returns the current view port.
     *
     * @author Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date   2012-06-03
     * @since  0.1
     *
     * @return A rectangle corresponding to the view port in the current level.
     */
    SDL_Rect GetViewPort () const;
    /**
     * Moves the upper left corner of the current view port.  The width and
     * height are not affected, so this effectively pans the view port around
     * the level.
     *
     * @author Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date   2012-06-03
     * @since  0.1
     *
     * @param [in] x The new x-coordinate of the upper left corner of the view
     * port, relative to the level.
     * @param [in] y The new y-coordinate of the upper left corner of the view
     * port, relative to the level.
     */
    void MoveViewPort (int x, int y);

    /**
     * Switches the back buffer and the front buffer and clears the new back
     * buffer to black.
     *
     * @author Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date   2012-06-03
     * @since  0.1
     */
    void Flip (void);

  private:
    SDL_Surface* surface;  ///< This window's backbuffer surface.
    SDL_Rect     viewPort; ///< The view port with respect to the current level.
};


}

#endif // #ifndef IMAGINARY_DISPLAY_HPP
