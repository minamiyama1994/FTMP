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
#ifndef FTMP_EMPTY_HPP
#define FTMP_EMPTY_HPP
namespace ftmp
{
	template < typename T >
	struct empty ;
}
#include"FTMP/dict.hpp"
#include"FTMP/integral.hpp"
#include"FTMP/list.hpp"
#include"FTMP/set.hpp"
#include"FTMP/to_list.hpp"
namespace ftmp
{
	template < typename ... T >
	struct empty < list < T ... > >
		: integral < bool , false >
	{
	} ;
	template < >
	struct empty < list < > >
		: integral < bool , true >
	{
	} ;
	template < typename ... seq >
	struct empty < set < seq ... > >
		: empty
		<
			list < seq ... >
		>
	{
	} ;
	template < typename ... seq >
	struct empty < dict < seq ... > >
		: empty
		<
			typename to_list < dict < seq ... > >::type
		>
	{
	} ;
}
#endif