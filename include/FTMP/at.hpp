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
#ifndef FTMP_AT_HPP
#define FTMP_AT_HPP
namespace ftmp
{
	template < typename T , typename index_type >
	struct at ;
}
#include<type_traits>
#include"FTMP/head.hpp"
#include"FTMP/id.hpp"
#include"FTMP/integral.hpp"
#include"FTMP/list.hpp"
#include"FTMP/tail.hpp"
namespace ftmp
{
	namespace detail
	{
		template < typename I , typename N , typename T , typename enable = void >
		struct skip ;
		template < typename index_type , index_type I , index_type N , typename ... T >
		struct skip < integral < index_type , I > , integral < index_type , N > , list < T ... > , typename std::enable_if < ( I == 0 ) >::type >
			: id < list < T ... > >
		{
		} ;
		template < typename index_type , index_type I , index_type N , typename ... T >
		struct skip < integral < index_type , I > , integral < index_type , N > , list < T ... > , typename std::enable_if < ( I != 0 && I < N / 2 ) >::type >
			: skip
			<
				integral < index_type , I - 1 > ,
				integral < index_type , N / 2 - 1 > ,
				typename tail < list < T ... > >::type
			>
		{
		} ;
		template < typename index_type , index_type I , index_type N , typename ... T >
		struct skip < integral < index_type , I > , integral < index_type , N > , list < T ... > , typename std::enable_if < ( I != 0 && I >= N / 2 ) >::type >
			: skip
			<
				integral < index_type , I - N / 2 > ,
				integral < index_type , N - N / 2 > ,
				typename skip
				<
					integral < index_type , N / 2 - 1 > ,
					integral < index_type , N / 2 > ,
					typename tail < list < T ... > >::type
				>::type
			>
		{
		} ;
	}
	template < typename ... T , typename index_type , index_type index >
	struct at < list < T ... > , integral < index_type , index > >
		: head
		<
			typename detail::skip
			<
				integral < index_type , index > ,
				integral < index_type , sizeof ... ( T ) > ,
				list < T ... >
			>::type
		>
	{
	} ;
}
#endif