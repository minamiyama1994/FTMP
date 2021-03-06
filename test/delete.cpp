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
#include"FTMP/delete.hpp"
static_assert ( ftmp::equal
<
	ftmp::delete_ < char , ftmp::list < char > >::type ,
	ftmp::list < >
>::type::value , "" ) ;
static_assert ( ftmp::equal
<
	ftmp::delete_ < char , ftmp::list < char , int > >::type ,
	ftmp::list < int >
>::type::value , "" ) ;
static_assert ( ftmp::equal
<
	ftmp::delete_ < char , ftmp::list < int > >::type ,
	ftmp::list < int >
>::type::value , "" ) ;
static_assert ( ftmp::equal
<
	ftmp::delete_ < char , ftmp::dict < ftmp::list < char , int > > >::type ,
	ftmp::dict < >
>::type::value , "" ) ;
static_assert ( ftmp::equal
<
	ftmp::delete_ < char , ftmp::dict < ftmp::list < short , int > > >::type ,
	ftmp::dict < ftmp::list < short , int > >
>::type::value , "" ) ;
static_assert ( ftmp::equal
<
	ftmp::delete_ < char , ftmp::dict < ftmp::list < char , int > , ftmp::list < short , int > > >::type ,
	ftmp::dict < ftmp::list < short , int > >
>::type::value , "" ) ;
auto main ( ) -> int { }
