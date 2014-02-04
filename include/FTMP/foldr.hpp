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
#ifndef FTMP_FOLDR_HPP
#define FTMP_FOLDR_HPP
namespace ftmp
{
	template < typename func , typename b , typename as >
	struct foldr ;
}
#include"FTMP/lambda.hpp"
#include"FTMP/detail/first_half.hpp"
#include"FTMP/detail/second_half.hpp"
namespace ftmp
{
	namespace detail
	{
		template < typename func , typename b , typename as1 , typename as2 >
		struct foldr_helper ;
		template < typename func , typename b , typename as1 , typename as2 >
		struct foldr_helper
			: foldr
			<
				func ,
				typename foldr
				<
					func ,
					b ,
					as2
				>::type ,
				as1
			>
		{
		} ;
	}
	template < typename func , typename b >
	struct foldr < func , b , list < > >
	{
		using type = b ;
	} ;
	template < typename func , typename b , typename as >
	struct foldr
		: detail::foldr_helper
		<
			func ,
			b ,
			typename detail::first_half < as >::type ,
			typename detail::second_half < as >::type
		>
	{
	} ;
	template < typename func , typename b , typename as >
	struct foldr < func , b , list < as > >
		: lambda < func >::template apply
		<
			as ,
			b
		>::type
	{
	} ;
}
#endif