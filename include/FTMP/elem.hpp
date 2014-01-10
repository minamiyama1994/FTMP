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
#ifndef FTMP_ELEM_HPP
#define FTMP_ELEM_HPP
namespace ftmp
{
	template < typename T , typename seq >
	struct elem ;
}
#include"FTMP/any.hpp"
#include"FTMP/equal.hpp"
#include"FTMP/list.hpp"
namespace ftmp
{
	template < typename T , typename seq >
	struct elem
		: any < equal < T , arg < 0 > > , seq >
	{
	} ;
}
#endif