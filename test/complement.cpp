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
#include"FTMP/complement.hpp"
static_assert ( ftmp::equal
<
	ftmp::complement < ftmp::list < char , short , int > , ftmp::list < char , short , int > >::type ,
	ftmp::list < >
>::type::value , "" ) ;
static_assert ( ftmp::equal
<
	ftmp::complement < ftmp::list < char , short , int , double > , ftmp::list < char , short , int > >::type ,
	ftmp::list < double >
>::type::value , "" ) ;
static_assert ( ftmp::equal
<
	ftmp::complement < ftmp::list < char , short , int > , ftmp::list < char , short , int , double > >::type ,
	ftmp::list < >
>::type::value , "" ) ;
static_assert ( ! ftmp::equal
<
	ftmp::complement < ftmp::list < char , short , int > , ftmp::list < char , short , int , double > >::type ,
	ftmp::list < double >
>::type::value , "" ) ;
static_assert ( ftmp::equal
<
	ftmp::complement < ftmp::list < char , float , short , int , double > , ftmp::list < char , short , int > >::type ,
	ftmp::list < float , double >
>::type::value , "" ) ;
static_assert ( ftmp::equal
<
	ftmp::complement < ftmp::set < char , short , int > , ftmp::set < char , short , int > >::type ,
	ftmp::set < >
>::type::value , "" ) ;
static_assert ( ftmp::equal
<
	ftmp::complement < ftmp::set < char , short , int , double > , ftmp::set < char , short , int > >::type ,
	ftmp::set < double >
>::type::value , "" ) ;
static_assert ( ftmp::equal
<
	ftmp::complement < ftmp::set < char , short , int > , ftmp::set < char , short , int , double > >::type ,
	ftmp::set < >
>::type::value , "" ) ;
static_assert ( ftmp::equal
<
	ftmp::complement < ftmp::set < char , float , short , int , double > , ftmp::set < char , short , int > >::type ,
	ftmp::set < float , double >
>::type::value , "" ) ;
static_assert ( ftmp::equal
<
	ftmp::complement < ftmp::set < char , float , short , int , double > , ftmp::set < char , short , int > >::type ,
	ftmp::set < double , float >
>::type::value , "" ) ;
auto main ( ) -> int { }
