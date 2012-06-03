# Imaginary: A Free Software Adventure RPG
# Copyright (C) 2012, the people listed in the AUTHORS file.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

configure_file (${CMAKE_CURRENT_SOURCE_DIR}/config.h.in
                ${CMAKE_CURRENT_BINARY_DIR}/config.h @ONLY)

set (imaginary_INCLUDE ${CMAKE_CURRENT_BINARY_DIR})
set (imaginary_SRCS    main.cpp game.cpp)

find_package (SDL       REQUIRED)
find_package (SDL_image REQUIRED)

include_directories (${imaginary_INCLUDE}
                     ${SDL_INCLUDE_DIR} ${SDLIMAGE_INCLUDE_DIR})
add_executable (imaginary ${imaginary_SRCS})
target_link_libraries (imaginary ${SDL_LIBRARY} ${SDLIMAGE_LIBRARY} SDLmain)