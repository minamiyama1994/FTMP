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
#ifndef FTMP_TO_SET_HPP
#define FTMP_TO_SET_HPP
namespace ftmp
{
	template < typename T >
	struct to_set ;
}
#include"FTMP/list.hpp"
#include"FTMP/to_set.hpp"
#include"FTMP/set.hpp"
#include"FTMP/unique.hpp"
namespace ftmp
{
	namespace detail
	{
		template < typename T >
		struct to_set_helper ;
		template < typename ... T >
		struct to_set_helper < list < T ... > >
			: set < T ... >
		{
		} ;
	}
	template < typename T >
	struct to_set
		: detail::to_set_helper < typename unique < T >::type >
	{
	} ;
}
#endif