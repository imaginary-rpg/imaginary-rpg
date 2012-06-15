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
#include "sound.hpp"

#include <string>
#include <stdexcept>
#include <SDL_mixer.h>

imaginary::Sound::Sound (std::string fileName)
  : chunk (Mix_LoadWAV (fileName.c_str ()))
{
  if (!chunk)
    {
      throw std::runtime_error ("Could not load sound file.");
    }
}

imaginary::Sound::~Sound ()
{
  Mix_FreeChunk (chunk);
}

void
imaginary::Sound::Play (int times)
{
  if (Mix_PlayChannel (-1, chunk, times) == -1)
    {
      throw std::runtime_error ("Could not play sound file.");
    }
}
