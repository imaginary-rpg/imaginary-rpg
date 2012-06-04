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

/// @file game.hpp
/// Contains the Game class and the Sdl class.

#ifndef IMAGINARY_GAME_HPP
#define IMAGINARY_GAME_HPP

#include "display.hpp"

struct SDL_Surface;
union SDL_Event;


namespace imaginary
{

/**
 * Manages the initialization and shutdown of SDL.
 *
 * @version 0.1
 * @author  Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
 * @date    2012-06-03
 * @since   0.1
 */
class Sdl
{
  public:
    /**
     * Initializes SDL and related libraries (SDL_image, SDL_mixer, etc).
     *
     * @author Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date   2012-06-03
     * @since  0.1
     */
    Sdl ();
    /**
     * Cleans up SDL and related libraries (SDL_image, SDL_mixer, etc).
     *
     * @author Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date   2012-06-03
     * @since  0.1
     */
    ~Sdl ();
};


/**
 * Manages the engine initialization, engine shutdown, and game loop.
 *
 * @version 0.1
 * @author  Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
 * @date    2012-06-03
 * @since   0.1
 *
 * @todo We might want to refactor this to separate engine-specific code from
 * game code.  That would tidy things up nicely.
 */
class Game
{
    static const unsigned WINDOW_WIDTH  = 640; ///< The default window height.
    static const unsigned WINDOW_HEIGHT = 480; ///< The default window width.
  public:
    /**
     * Constructs a new Game object, and initializes everything that is needed
     * before the game can start, including SDL.
     *
     * @version 0.1
     * @author  Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date    2012-06-02
     * @since   0.1
     */
    Game ();
    /**
     * Destructs an existing Game object, and terminates everything in use by
     * the engine and SDL.
     *
     * @version 0.1
     * @author  Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date    2012-06-02
     * @since   0.1
     */
    ~Game ();
    /**
     * Starts the game loop.  All updating and rendering commands are called
     * within here.
     *
     * @version 0.1
     * @author  Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date    2012-06-02
     * @since   0.1
     *
     * @return The return code to give back to the operating system.  Should
     * usually be 0, unless something exceptional happens.
     */
    int Run ();

  private:
    /**
     * Handles any events that SDL produces, including WM events, input events,
     * and user events.
     *
     * @version 0.1
     * @author  Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date    2012-06-02
     * @since   0.1
     *
     * @param [in] event The exact event to handle.
     */
    void HandleEvent (SDL_Event *event);
    /**
     * Updates anything in the engine and the game that needs to be updated
     * every frame.
     *
     * @version 0.1
     * @author  Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date    2012-06-02
     * @since   0.1
     */
    void Update ();
    /**
     * Renders the current frame to the screen.
     *
     * @version 0.1
     * @author  Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date    2012-06-02
     * @since   0.1
     */
    void Render ();

    // C++ guarantees that objects in a class will be constructed in the order
    // they are declared here.  SDL will always be initialized first.  Yay!
    Sdl     sdl;       ///< SDL manager.
    Display display;   ///< The Display that manages the game window.
    bool    isRunning; ///< Whether should continue running after this frame.
};


}

#endif // #ifndef IMAGINARY_GAME_HPP
