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

#ifndef IMAGINARY_GAME_HPP
#define IMAGINARY_GAME_HPP

struct SDL_Surface;

namespace imaginary
{

class Game
{
  public:
    Game ();
    ~Game ();

    int Run ();

  private:
    SDL_Surface* displaySurface;
};

}

#endif // #ifndef IMAGINARY_GAME_HPP
