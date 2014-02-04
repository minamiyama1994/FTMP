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
#include"FTMP/case.hpp"
static_assert ( ftmp::equal
<
	ftmp::case_ < char >::of
	<
		ftmp::match < char , long > ,
		ftmp::match < short , int > ,
		ftmp::match < int , short > ,
		ftmp::match < long , char > ,
		ftmp::match < ftmp::pattern < 0 > , ftmp::pattern < 0 > >
	>::type ,
	long
>::type::value , "" ) ;
static_assert ( ftmp::equal
<
	ftmp::case_ < short >::of
	<
		ftmp::match < char , long > ,
		ftmp::match < short , int > ,
		ftmp::match < int , short > ,
		ftmp::match < long , char > ,
		ftmp::match < ftmp::pattern < 0 > , ftmp::pattern < 0 > >
	>::type ,
	int
>::type::value , "" ) ;
static_assert ( ftmp::equal
<
	ftmp::case_ < int >::of
	<
		ftmp::match < char , long > ,
		ftmp::match < short , int > ,
		ftmp::match < int , short > ,
		ftmp::match < long , char > ,
		ftmp::match < ftmp::pattern < 0 > , ftmp::pattern < 0 > >
	>::type ,
	short
>::type::value , "" ) ;
static_assert ( ftmp::equal
<
	ftmp::case_ < long >::of
	<
		ftmp::match < char , long > ,
		ftmp::match < short , int > ,
		ftmp::match < int , short > ,
		ftmp::match < long , char > ,
		ftmp::match < ftmp::pattern < 0 > , ftmp::pattern < 0 > >
	>::type ,
	char
>::type::value , "" ) ;
static_assert ( ftmp::equal
<
	ftmp::case_ < float >::of
	<
		ftmp::match < char , long > ,
		ftmp::match < short , int > ,
		ftmp::match < int , short > ,
		ftmp::match < long , char > ,
		ftmp::match < ftmp::pattern < 0 > , ftmp::pattern < 0 > >
	>::type ,
	float
>::type::value , "" ) ;
static_assert ( ! ftmp::equal
<
	ftmp::case_ < char >::of
	<
		ftmp::match < char , long > ,
		ftmp::match < short , int > ,
		ftmp::match < int , short > ,
		ftmp::match < long , char > ,
		ftmp::match < ftmp::pattern < 0 > , ftmp::pattern < 0 > >
	>::type ,
	float
>::type::value , "" ) ;
static_assert ( ftmp::equal
<
	ftmp::case_ < ftmp::list < char , short , int , long > >::of
	<
		ftmp::match
		<
			ftmp::list < ftmp::pattern < 0 > , short , ftmp::pattern < 1 > , ftmp::pattern < 2 > > ,
			ftmp::list < ftmp::pattern < 2 > , ftmp::pattern < 1 > , short , ftmp::pattern < 0 > >
		>
	>::type ,
	ftmp::list < long , int , short , char >
>::type::value , "" ) ;
static_assert ( ! ftmp::equal
<
	ftmp::case_ < ftmp::list < char , short , int , long > >::of
	<
		ftmp::match
		<
			ftmp::list < ftmp::pattern < 0 > , short , ftmp::pattern < 1 > , ftmp::pattern < 2 > > ,
			ftmp::list < ftmp::pattern < 2 > , ftmp::pattern < 1 > , short , ftmp::pattern < 0 > >
		>
	>::type ,
	ftmp::list < char , short , int , long >
>::type::value , "" ) ;
auto main ( ) -> int { }
