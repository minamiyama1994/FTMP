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
#ifndef FTMP_FOLDL_HPP
#define FTMP_FOLDL_HPP
namespace ftmp
{
	template < typename func , typename a , typename bs >
	struct foldl ;
}
#include"FTMP/lambda.hpp"
#include"FTMP/detail/first_half.hpp"
#include"FTMP/detail/second_half.hpp"
namespace ftmp
{
	namespace detail
	{
		template < typename func , typename a , typename bs1 , typename bs2 >
		struct foldl_helper ;
		template < typename func , typename a , typename bs1 , typename bs2 >
		struct foldl_helper
			: foldl
			<
				func ,
				typename foldl
				<
					func ,
					a ,
					bs1
				>::type ,
				bs2
			>
		{
		} ;
	}
	template < typename func , typename a >
	struct foldl < func , a , list < > >
	{
		using type = a ;
	} ;
	template < typename func , typename a , typename bs >
	struct foldl
		: detail::foldl_helper
		<
			func ,
			a ,
			typename detail::first_half < bs >::type ,
			typename detail::second_half < bs >::type
		>
	{
	} ;
	template < typename func , typename a , typename bs >
	struct foldl < func , a , list < bs > >
		: lambda < func >::template apply
		<
			a ,
			bs
		>::type
	{
	} ;
}
#endif