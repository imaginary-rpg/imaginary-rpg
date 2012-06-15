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

find_package (Doxygen)
if (DOXYGEN_FOUND)
  configure_file (${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
                  ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)

  add_custom_target (doc
                     ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
                     WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                     COMMENT "Generating API documentation with Doxygen"
                     VERBATIM)
endif (DOXYGEN_FOUND)