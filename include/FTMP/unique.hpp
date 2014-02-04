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
#ifndef FTMP_UNIQUE_HPP
#define FTMP_UNIQUE_HPP
namespace ftmp
{
	template < typename seq >
	struct unique ;
}
#include"FTMP/cons.hpp"
#include"FTMP/equal.hpp"
#include"FTMP/eval.hpp"
#include"FTMP/filter.hpp"
#include"FTMP/foldr.hpp"
#include"FTMP/id.hpp"
#include"FTMP/list.hpp"
#include"FTMP/not.hpp"
#include"FTMP/unique.hpp"
namespace ftmp
{
	namespace detail
	{
		template < typename T1 , typename T2 >
		struct eval_filter
			: filter
			<
				not_ < equal < arg < 0 > , T1 > > ,
				T2
			>
		{
		} ;
	}
	template < typename seq >
	struct unique
		: foldr
		<
			eval < cons < id < arg < 0 > > , detail::eval_filter < arg < 0 > , arg < 1 > > > > ,
			list < > ,
			seq
		>
	{
	} ;
}
#endif