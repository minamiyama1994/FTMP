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
#ifndef FTMP_INTERSECTION_HPP
#define FTMP_INTERSECTION_HPP
namespace ftmp
{
	template < typename T1 , typename T2 >
	struct intersection ;
}
#include"FTMP/cons.hpp"
#include"FTMP/elem.hpp"
#include"FTMP/eval_if.hpp"
#include"FTMP/foldr.hpp"
#include"FTMP/id.hpp"
#include"FTMP/list.hpp"
#include"FTMP/to_set.hpp"
#include"FTMP/set.hpp"
namespace ftmp
{
	template < typename ... T1 , typename ... T2 >
	struct intersection < set < T1 ... > , set < T2 ... > >
		: to_set
		<
			typename foldr
			<
				eval_if
				<
					elem
					<
						arg < 0 > ,
						list < T2 ... >
					> ,
					cons < arg < 0 > , arg < 1 > > ,
					id < arg < 1 > >
				> ,
				list < > ,
				list < T1 ... >
			>::type
		>
	{
	} ;
}
#endif