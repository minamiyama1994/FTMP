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
#ifndef FTMP_RUNTIME_CASE_HPP
#define FTMP_RUNTIME_CASE_HPP
namespace ftmp {
namespace runtime {
namespace detail {
template <typename T> class case_pattern_matcher;
}
template <typename T> auto case_(T &&t) -> detail::case_pattern_matcher<T>;
template <typename T> struct match;
}
}
namespace ftmp {
namespace runtime {
namespace detail {
template <typename T　> class case_pattern_matcher {
  T *value;

public:
  case_pattern_matcher(T &o);
  auto operator(match<T> matcher) -> decltype(matcher(*value));
};
template <typename T>
case_pattern_matcher<T>::case_pattern_matcher(T &o)
    : value{ &o } {}
template <typename T>
auto case_pattern_matcher<T>::operator(match<T> matcher)
    -> decltype(matcher(*value)) {
  return matcher(*value);
}
}
template <typename T> auto case_(T &&o) -> detail::case_pattern_matcher<T> {
  return detail::case_pattern_matcher(std::forward<T &>(o));
}
template <typename T> struct match {};
}
}
#endif