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
#include "FTMP/at.hpp"
#include "FTMP/equal.hpp"
static_assert(
    ftmp::equal<ftmp::at<ftmp::list<char, short, int, long, float, double>,
                         ftmp::integral<int, 0> >::type,
                char>::type::value,
    "");
static_assert(
    ftmp::equal<ftmp::at<ftmp::list<char, short, int, long, float, double>,
                         ftmp::integral<int, 1> >::type,
                short>::type::value,
    "");
static_assert(
    ftmp::equal<ftmp::at<ftmp::list<char, short, int, long, float, double>,
                         ftmp::integral<int, 2> >::type,
                int>::type::value,
    "");
static_assert(
    ftmp::equal<ftmp::at<ftmp::list<char, short, int, long, float, double>,
                         ftmp::integral<int, 3> >::type,
                long>::type::value,
    "");
static_assert(
    ftmp::equal<ftmp::at<ftmp::list<char, short, int, long, float, double>,
                         ftmp::integral<int, 4> >::type,
                float>::type::value,
    "");
static_assert(
    ftmp::equal<ftmp::at<ftmp::list<char, short, int, long, float, double>,
                         ftmp::integral<int, 5> >::type,
                double>::type::value,
    "");
static_assert(
    !ftmp::equal<ftmp::at<ftmp::list<char, short, int, long, float, double>,
                          ftmp::integral<int, 0> >::type,
                 double>::type::value,
    "");
auto main() -> int {}
