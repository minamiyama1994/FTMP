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
#ifndef FTMP_AND_HPP
#define FTMP_AND_HPP
namespace ftmp
{
	template < typename T1 , typename T2 = void >
	struct and_ ;
}
#include"FTMP/foldr.hpp"
#include"FTMP/integral.hpp"
#include"FTMP/list.hpp"
#include"FTMP/nand.hpp"
#include"FTMP/not.hpp"
namespace ftmp
{
	template < typename ... T >
	struct and_ < list < T ... > , void >
		: foldr
		<
			and_ < arg < 0 > , arg < 1 > > ,
			integral < bool , true > ,
			list < T ... >
		>
	{
	} ;
	template < typename T1 , typename T2 >
	struct and_
		: not_
		<
			typename nand
			<
				typename T1::type ,
				typename T2::type
			>::type
		>
	{
	} ;
}
#endif