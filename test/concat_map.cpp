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
#include"FTMP/concat_map.hpp"
static_assert ( ftmp::equal
<
	ftmp::concat_map < ftmp::list < ftmp::arg < 0 > > , ftmp::list < > >::type ,
	ftmp::list < >
>::type::value , "" ) ;
static_assert ( ftmp::equal
<
	ftmp::concat_map < ftmp::list < ftmp::arg < 0 > > , ftmp::list < > >::type ,
	ftmp::list < >
>::type::value , "" ) ;
static_assert ( ftmp::equal
<
	ftmp::concat_map < ftmp::list < ftmp::arg < 0 > > , ftmp::list < int > >::type ,
	ftmp::list < int >
>::type::value , "" ) ;
static_assert ( ftmp::equal
<
	ftmp::concat_map < ftmp::list < ftmp::arg < 0 > > , ftmp::list < int , short > >::type ,
	ftmp::list < int , short >
>::type::value , "" ) ;
static_assert ( ftmp::equal
<
	ftmp::concat_map < ftmp::list < ftmp::arg < 0 > , ftmp::arg < 0 > > , ftmp::list < > >::type ,
	ftmp::list < >
>::type::value , "" ) ;
static_assert ( ftmp::equal
<
	ftmp::concat_map < ftmp::list < ftmp::arg < 0 > , ftmp::arg < 0 > > , ftmp::list < > >::type ,
	ftmp::list < >
>::type::value , "" ) ;
static_assert ( ftmp::equal
<
	ftmp::concat_map < ftmp::list < ftmp::arg < 0 > , ftmp::arg < 0 > > , ftmp::list < int > >::type ,
	ftmp::list < int , int >
>::type::value , "" ) ;
static_assert ( ftmp::equal
<
	ftmp::concat_map < ftmp::list < ftmp::arg < 0 > , ftmp::arg < 0 > > , ftmp::list < int , short > >::type ,
	ftmp::list < int , int , short , short >
>::type::value , "" ) ;
auto main ( ) -> int { }
