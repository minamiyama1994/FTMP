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
#ifndef FTMP_INSERT_HPP
#define FTMP_INSERT_HPP
namespace ftmp
{
	template < typename T , typename T1 , typename T2 = void >
	struct insert ;
}
#include"FTMP/at.hpp"
#include"FTMP/dict.hpp"
#include"FTMP/equal.hpp"
#include"FTMP/eval.hpp"
#include"FTMP/filter.hpp"
#include"FTMP/id.hpp"
#include"FTMP/integral.hpp"
#include"FTMP/list.hpp"
#include"FTMP/not.hpp"
#include"FTMP/set.hpp"
#include"FTMP/to_list.hpp"
#include"FTMP/union.hpp"
namespace ftmp
{
	namespace detail
	{
		template < typename k , typename a , typename dict_ >
		struct insert_dict_helper ;
		template < typename k , typename a , typename ... dict_ >
		struct insert_dict_helper < k , a , list < dict_ ... > >
			: dict < list < k , a > , dict_ ... >
		{
		} ;
	}
	template < typename k , typename a , typename dict_ >
	struct insert
		: detail::insert_dict_helper
		<
			k ,
			a ,
			typename filter
			<
				not_ < eval < equal < at < arg < 0 > , integral < int , 0 > > , id < k > > > > ,
				typename to_list < dict_ >::type
			>::type
		>
	{
	} ;
	template < typename T , typename s >
	struct insert < T , s , void >
		: union_
		<
			set < T > ,
			s
		>
	{
	} ;
}
#endif