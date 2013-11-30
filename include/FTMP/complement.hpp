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
#ifndef FTMP_COMPLEMENT_HPP
#define FTMP_COMPLEMENT_HPP
namespace ftmp
{
	template < typename T1 , typename T2 >
	struct complement ;
}
#include"FTMP/elem.hpp"
#include"FTMP/filter.hpp"
#include"FTMP/list.hpp"
#include"FTMP/not.hpp"
#include"FTMP/set.hpp"
#include"FTMP/to_set.hpp"
namespace ftmp
{
	template < typename ... T1 , typename ... T2 >
	struct complement < list < T1 ... > , list < T2 ... > >
		: filter
		<
			not_ < elem < arg < 0 > , list < T2 ... > > > ,
			list < T1 ... >
		>
	{
	} ;
	template < typename ... T1 , typename ... T2 >
	struct complement < set < T1 ... > , set < T2 ... > >
		: to_set
		<
			typename complement
			<
				list < T1 ... > ,
				list < T2 ... >
			>::type
		>
	{
	} ;
}
#endif