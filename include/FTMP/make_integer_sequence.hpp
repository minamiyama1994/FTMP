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
#ifndef FTMP_MAKE_INTEGER_SEQUENCE_HPP
#define FTMP_MAKE_INTEGER_SEQUENCE_HPP
namespace ftmp
{
	template < typename begin , typename end >
	struct make_integer_sequence ;
}
#include"FTMP/append.hpp"
#include"FTMP/integral.hpp"
#include"FTMP/list.hpp"
namespace ftmp
{
	template < typename T , T begin >
	struct make_integer_sequence < integral < T , begin > , integral < T , begin > >
		: list < >
	{
	} ;
	template < typename T , T begin >
	struct make_integer_sequence < integral < T , begin > , integral < T , begin + 1 > >
		: list < integral < T , begin > >
	{
	} ;
	template < typename T , T begin , T end >
	struct make_integer_sequence < integral < T , begin > , integral < T , end > >
		: append
		<
			typename make_integer_sequence < integral < T , begin > , integral < T , begin + ( end - begin ) / 2 > >::type ,
			typename make_integer_sequence < integral < T , begin + ( end - begin ) / 2 > , integral < T , end > >::type
		>
	{
	} ;
}
#endif