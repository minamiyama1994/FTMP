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
#ifndef FTMP_BREAK_HPP
#define FTMP_BREAK_HPP
namespace ftmp
{
	template < typename func , typename seq >
	struct break_ ;
}
#include"FTMP/and.hpp"
#include"FTMP/at.hpp"
#include"FTMP/cons.hpp"
#include"FTMP/eval.hpp"
#include"FTMP/eval_if.hpp"
#include"FTMP/id.hpp"
#include"FTMP/integral.hpp"
#include"FTMP/lambda.hpp"
#include"FTMP/list.hpp"
#include"FTMP/map.hpp"
#include"FTMP/reverse.hpp"
namespace ftmp
{
	namespace detail
	{
		template < typename func , typename seq >
		struct break_helper
			: foldl
			<
				ftmp::eval_if
				<
					ftmp::and_
					<
						typename ftmp::lambda < func >::template apply < ftmp::arg < 1 > > ,
						ftmp::at < ftmp::arg < 0 > , ftmp::integral < int , 2 > >
					> ,
					eval < list
					<
						ftmp::eval < ftmp::cons
						<
							ftmp::id < ftmp::arg < 1 > > ,
							ftmp::at < ftmp::arg < 0 > , ftmp::integral < int , 0 > >
						> > ,
						ftmp::at < ftmp::arg < 0 > , ftmp::integral < int , 1 > > ,
						integral < bool , true >
					> > ,
					eval < list
					<
						ftmp::at < ftmp::arg < 0 > , ftmp::integral < int , 0 > > ,
						ftmp::eval < ftmp::cons
						<
							ftmp::id < ftmp::arg < 1 > > ,
							ftmp::at < ftmp::arg < 0 > , ftmp::integral < int , 1 > >
						> > ,
						integral < bool , false >
					> >
				> ,
				list < list < > , list < > , integral < bool , true > > ,
				seq
			>
		{
		} ;
	}
	template < typename func , typename seq >
	struct break_
		: map
		<
			reverse < arg < 0 > > ,
			typename map
			<
				at
				<
					typename ftmp::detail::break_helper < func , seq >::type ,
					arg < 0 >
				> ,
				list < integral < int , 0 > , integral < int , 1 > >
			>::type
		>
	{
	} ;
}
#endif