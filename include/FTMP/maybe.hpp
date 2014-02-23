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
#ifndef FTMP_MAYBE_HPP
#define FTMP_MAYBE_HPP
namespace ftmp {
template <typename T> struct just;
struct nothing;
template <typename d, typename fun, typename m> struct maybe;
}
#include "FTMP/if.hpp"
#include "FTMP/equal.hpp"
#include "FTMP/id.hpp"
#include "FTMP/lambda.hpp"
#include "FTMP/eval.hpp"
namespace ftmp {
template <typename T> struct just {
  using type = T;
};
struct nothing {};
template <typename d, typename fun, typename m>
struct maybe
    : if_<equal<m, nothing>, id<d>,
          typename eval<
              typename lambda<fun>::template apply<m> >::type>::type {};
}
#endif