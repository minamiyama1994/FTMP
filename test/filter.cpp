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
#include"FTMP/filter.hpp"
template < typename >
struct is_odd ;
template < typename T , T N >
struct is_odd < ftmp::integral < T , N > >
	: ftmp::integral < bool , N % 2 != 0 >
{
} ;
static_assert ( ftmp::equal
<
	ftmp::filter < is_odd < ftmp::arg < 0 > > , ftmp::list < ftmp::integral < int , 0 > , ftmp::integral < int , 1 > , ftmp::integral < int , 2 > , ftmp::integral < int , 3 > , ftmp::integral < int , 4 > > >::type ,
	ftmp::list < ftmp::integral < int , 1 > , ftmp::integral < int , 3 > >
>::type::value , "" ) ;
static_assert ( ftmp::equal
<
	ftmp::filter < ftmp::not_ < is_odd < ftmp::arg < 0 > > > , ftmp::list < ftmp::integral < int , 0 > , ftmp::integral < int , 1 > , ftmp::integral < int , 2 > , ftmp::integral < int , 3 > , ftmp::integral < int , 4 > > >::type ,
	ftmp::list < ftmp::integral < int , 0 > , ftmp::integral < int , 2 > , ftmp::integral < int , 4 > >
>::type::value , "" ) ;
static_assert ( ftmp::equal
<
	ftmp::filter < is_odd < ftmp::arg < 0 > > , ftmp::set < ftmp::integral < int , 0 > , ftmp::integral < int , 1 > , ftmp::integral < int , 2 > , ftmp::integral < int , 3 > , ftmp::integral < int , 4 > > >::type ,
	ftmp::set < ftmp::integral < int , 3 > , ftmp::integral < int , 1 > >
>::type::value , "" ) ;
static_assert ( ftmp::equal
<
	ftmp::filter < ftmp::not_ < is_odd < ftmp::arg < 0 > > > , ftmp::set < ftmp::integral < int , 0 > , ftmp::integral < int , 1 > , ftmp::integral < int , 2 > , ftmp::integral < int , 3 > , ftmp::integral < int , 4 > > >::type ,
	ftmp::set < ftmp::integral < int , 2 > , ftmp::integral < int , 0 > , ftmp::integral < int , 4 > >
>::type::value , "" ) ;
auto main ( ) -> int { }
