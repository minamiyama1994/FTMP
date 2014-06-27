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
#ifndef FTMP_QUICK_SORT_HPP
#define FTMP_QUICK_SORT_HPP
namespace ftmp
{
	template < typename func , typename seq >
	struct quick_sort ;
	struct LT ;
	struct GT ;
	struct EQ ;
}
#include"FTMP/concat.hpp"
#include"FTMP/equal.hpp"
#include"FTMP/eval.hpp"
#include"FTMP/filter.hpp"
#include"FTMP/id.hpp"
#include"FTMP/list.hpp"
#include"FTMP/lambda.hpp"
#include"FTMP/or.hpp"
namespace ftmp
{
	template < typename func , typename head , typename ... seq >
	struct quick_sort < func , list < head , seq ... > >
		: concat
		<
			list
			<
				typename quick_sort
				<
					func ,
					typename filter
					<
						eval < equal
						<
							typename lambda < func >::template apply < head , arg < 0 > >::type ,
							id < LT >
						> > ,
						list < seq ... >
					>::type
				>::type ,
				list < head > ,
				typename quick_sort
				<
					func ,
					typename filter
					<
						eval < or_
						<
							eval < equal
							<
								typename lambda < func >::template apply < head , arg < 0 > >::type ,
								id < GT >
							> > ,
							eval < equal
							<
								typename lambda < func >::template apply < head , arg < 0 > >::type ,
								id < EQ >
							> >
						> > ,
						list < seq ... >
					>::type
				>::type
			>
		>
	{
	} ;
}
#endif
