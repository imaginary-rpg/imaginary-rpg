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

/// @file sound.hpp
/// Contains the Sound class.

#ifndef IMAGINARY_SOUND_HPP
#define IMAGINARY_SOUND_HPP

#include <string>

struct Mix_Chunk;

namespace imaginary
{


/**
 * A buffer that holds an audio recording.  A Sound can play itself.
 *
 * @version 0.1
 * @author  Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
 * @date    2012-06-04
 * @since   0.1
 */
class Sound
{
  public:
    /**
     * Constructs a new Sound object by loading it from a specified path.  All
     * formats that are supported by SDL_mixer are supported by this class.
     *
     * @author Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date   2012-06-04
     * @since  0.1
     *
     * @param [in] fileName The path to the sound file to load.
     */
    Sound (std::string fileName);
    /**
     * Destructs an existing Sound object and frees any memory associated with
     * it.
     *
     * @author Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date   2012-06-04
     * @since  0.1
     */
    ~Sound ();

    /**
     * Plays the Sound.
     *
     * @author Patrick M. Niedzielski <PatrickNiedzielski@gmail.com>
     * @date   2012-06-04
     * @since  0.1
     *
     * @param [in] times The number of times to loop the sound.  For infinite
     * looping, this should be -1.
     */
    void Play (int times);

  private:
    Mix_Chunk*   chunk;     ///< The actual sound buffer.
};


}

#endif // #ifndef IMAGINARY_IMAGE_HPP
