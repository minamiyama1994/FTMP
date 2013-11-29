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
#ifndef FTMP_EQUAL_HPP
#define FTMP_EQUAL_HPP
namespace ftmp
{
	template < typename T1 , typename T2 >
	struct equal ;
}
#include"FTMP/all.hpp"
#include"FTMP/and.hpp"
#include"FTMP/at.hpp"
#include"FTMP/dict.hpp"
#include"FTMP/elem.hpp"
#include"FTMP/eval.hpp"
#include"FTMP/foldl.hpp"
#include"FTMP/integral.hpp"
#include"FTMP/list.hpp"
#include"FTMP/set.hpp"
#include"FTMP/size.hpp"
#include"FTMP/zip.hpp"
namespace ftmp
{
	template < typename T >
	struct equal < T , T >
		: integral < bool , true >
	{
	} ;
	template < typename T1 , typename T2 >
	struct equal
		: integral < bool , false >
	{
	} ;
	template < typename ... T1 >
	struct equal < list < T1 ... > , list < T1 ... > >
		: integral < bool , true >
	{
	} ;
	template < typename ... T1 , typename ... T2 >
	struct equal < list < T1 ... > , list < T2 ... > >
		: and_
		<
			integral
			<
				bool ,
				size < list < T1 ... > >::type::value == size < list < T2 ... > >::type::value
			> ,
			typename all
			<
				eval
				<
					equal
					<
						at < arg < 0 > , integral < int , 0 > > ,
						at < arg < 0 > , integral < int , 1 > >
					>
				> ,
				typename zip < list < T1 ... > , list < T2 ... > >::type
			>::type
		>
	{
	} ;
	template < typename ... T1 >
	struct equal < set < T1 ... > , set < T1 ... > >
		: integral < bool , true >
	{
	} ;
	template < typename ... T1 , typename ... T2 >
	struct equal < set < T1 ... > , set < T2 ... > >
		: and_
		<
			typename foldl
			<
				and_
				<
					arg < 0 > ,
					elem < arg < 1 > , list < T2 ... > >
				> ,
				integral < bool , true > ,
				list < T1 ... >
			>::type ,
			typename foldl
			<
				and_
				<
					arg < 0 > ,
					elem < arg < 1 > , list < T1 ... > >
				> ,
				integral < bool , true > ,
				list < T2 ... >
			>::type
		>
	{
	} ;
	template < typename ... T1 >
	struct equal < dict < T1 ... > , dict < T1 ... > >
		: integral < bool , true >
	{
	} ;
	template < typename ... T1 , typename ... T2 >
	struct equal < dict < T1 ... > , dict < T2 ... > >
		: equal < set < T1 ... > , set < T2 ... > >
	{
	} ;
}
#endif