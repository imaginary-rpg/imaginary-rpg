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

project (imaginary)
cmake_minimum_required (VERSION 2.6)

set (CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

#include (Defaults)
#include (CompilerChecks)
include (Version)
#include (Uninstall)

add_subdirectory (src)
add_subdirectory (doc)