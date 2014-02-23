/*
 *  Functional Template Meta Programming Library
 *  Copyright (C) 2013  Masakazu Minamiyama
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "FTMP/all.hpp"
static_assert(
    ftmp::all<ftmp::arg<0>,
              ftmp::list<ftmp::integral<bool, true>, ftmp::integral<bool, true>,
                         ftmp::integral<bool, true>,
                         ftmp::integral<bool, true> > >::type::value,
    "");
template <typename> struct int_to_bool;
template <int N>
struct int_to_bool<ftmp::integral<int, N> > : ftmp::integral<bool, N != 0> {};
static_assert(
    ftmp::all<ftmp::arg<0>,
              ftmp::list<ftmp::integral<int, 1>, ftmp::integral<int, 2>,
                         ftmp::integral<int, 3>,
                         ftmp::integral<int, 4> > >::type::value,
    "");
static_assert(
    !ftmp::all<int_to_bool<ftmp::arg<0> >,
               ftmp::list<ftmp::integral<int, 0>, ftmp::integral<int, 1>,
                          ftmp::integral<int, 2>,
                          ftmp::integral<int, 3> > >::type::value,
    "");
auto main() -> int {}
