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

#include "geometry.hpp"

struct SDL_Surface;

namespace imaginary
{

struct Rectangle;
struct Point;


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
 *
 * @todo I think we'll want to open up the window in this class, not in
 * imaginary::Game.  It's important that we figure out how to get the SDL_Init()
 * function called before this object is made, though, and I don't like the
 * current solution of using the free store.
 *
 * @todo We need to make this surface available to anyone else to blit other
 * surfaces to the screen; we could use friends or pass the surfaces of other
 * images to a method of this class.  The latter looks attractive as an
 * alternative.
 */
class Display
{
  public:
    /**
     * Constructs a new Display object.  Because each Display doesn't currently
     * manage the construction of the window and its display surface, this has
     * to be passed in.
     *
     * @author Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date   2012-06-03
     * @since  0.1
     *
     * @param [in] buffer   The constructed display buffer that this Display
     * will manage.
     * @param [in] viewPort The initial view port of this display in the level.
     */
    Display (SDL_Surface* buffer, Rectangle viewPort);
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
     * @return A Rectangle corresponding to the view port in the current level.
     */
    Rectangle GetViewPort () const;
    /**
     * Moves the upper left corner of the current view port.  The width and
     * height are not affected, so this effectively pans the view port around
     * the level.
     *
     * @author Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date   2012-06-03
     * @since  0.1
     *
     * @param [in] newLocation The coordinates of the new uper left corner of
     * the view port with respect to the level.
     */
    void MoveViewPort (Point newLocation);
    /**
     * Returns the surface of this Display.  Because of the way SDL works and
     * because of our design, this is current necessary.
     *
     * @author Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date   2012-06-03
     * @since  0.1
     *
     * @return This window's backbuffer surface.
     */
    SDL_Surface* GetSurface () const;

  private:
    SDL_Surface* surface;  ///< This window's backbuffer surface.
    Rectangle    viewPort; ///< The view port with respect to the current level.
};


}

#endif // #ifndef IMAGINARY_DISPLAY_HPP
