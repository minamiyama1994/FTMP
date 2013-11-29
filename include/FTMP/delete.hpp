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
#ifndef FTMP_DELETE_HPP
#define FTMP_DELETE_HPP
namespace ftmp
{
	template < typename k , typename map >
	struct delete_ ;
}
#include"FTMP/at.hpp"
#include"FTMP/equal.hpp"
#include"FTMP/eval.hpp"
#include"FTMP/filter.hpp"
#include"FTMP/id.hpp"
#include"FTMP/integral.hpp"
#include"FTMP/map.hpp"
#include"FTMP/not.hpp"
#include"FTMP/to_list.hpp"
#include"FTMP/to_dict.hpp"
namespace ftmp
{
	template < typename k , typename map >
	struct delete_
		: to_dict
		<
			typename filter
			<
				not_ < eval < equal < id < k > , at < arg < 0 > , integral < int , 0 > > > > > ,
				typename to_list < map >::type
			>::type
		>
	{
	} ;
}
#endif