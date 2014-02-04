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
#ifndef FTMP_FILTER_HPP
#define FTMP_FILTER_HPP
namespace ftmp
{
	template < typename func , typename seq >
	struct filter ;
}
#include"FTMP/cons.hpp"
#include"FTMP/eval_if.hpp"
#include"FTMP/filter.hpp"
#include"FTMP/foldr.hpp"
#include"FTMP/id.hpp"
#include"FTMP/lambda.hpp"
#include"FTMP/list.hpp"
#include"FTMP/to_set.hpp"
#include"FTMP/set.hpp"
namespace ftmp
{
	namespace detail
	{
		template < typename func , typename T >
		struct eval_lambda
			: lambda < func >::template apply < T >::type::type
		{
		} ;
	}
	template < typename func , typename seq >
	struct filter
		: foldr
		<
			eval_if
			<
				detail::eval_lambda < func , arg < 0 > > ,
				cons < arg < 0 > , arg < 1 > > ,
				id < arg < 1 > >
			> ,
			list < > ,
			seq
		>
	{
	} ;
	template < typename func , typename ... seq >
	struct filter < func , set < seq ... > >
		: to_set
		<
			typename filter
			<
				func ,
				list < seq ... >
			>::type
		>
	{
	} ;
}
#endif