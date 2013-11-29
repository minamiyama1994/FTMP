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
#ifndef FTMP_LAMBDA_HPP
#define FTMP_LAMBDA_HPP
namespace ftmp
{
	template < typename func >
	struct lambda ;
	template < unsigned int index >
	struct arg ;
}
#include"FTMP/at.hpp"
#include"FTMP/cons.hpp"
#include"FTMP/head.hpp"
#include"FTMP/id.hpp"
#include"FTMP/list.hpp"
#include"FTMP/tail.hpp"
namespace ftmp
{
	template < unsigned int index >
	struct arg
	{
		using type = arg ;
	} ;
	template < typename T >
	struct meta
	{
		using type = T ;
	} ;
	namespace detail
	{
		template < typename T , unsigned int N >
		struct at
			: ftmp::at < T , ftmp::integral < unsigned int , N > >
		{
		} ;
		template < typename func , typename args >
		struct apply ;
		template < typename Ts , typename args >
		struct apply_helper ;
		template < typename func , typename list_ >
		struct apply_impl ;
		template < template < typename ... T_ > class func_template , typename ... T , typename ... args >
		struct apply_impl < func_template < T ... > , ftmp::list < args ... > >
		{
			using type = func_template < args ... > ;
		} ;
		template < unsigned int N , typename ... Ts , typename args >
		struct apply_helper < ftmp::list < ftmp::arg < N > , Ts ... > , args >
			: cons
			<
				typename at < args , N >::type ,
				typename apply_helper < ftmp::list < Ts ... > , args >::type
			>
		{
		} ;
		template < typename T , typename ... Ts , typename args >
		struct apply_helper < ftmp::list < ftmp::meta < T > , Ts ... > , args >
			: cons
			<
				typename ftmp::meta < T >::type ,
				typename apply_helper < ftmp::list < Ts ... > , args >::type
			>
		{
		} ;
		template < typename T , typename args >
		struct apply_helper
			: ftmp::cons
			<
				typename apply < typename head < T >::type , args >::type ,
				typename apply_helper < typename tail < T >::type , args >::type
			>
		{
		} ;
		template < typename args >
		struct apply_helper < ftmp::list < > , args >
		{
			using type = ftmp::list < > ;
		} ;
		template < typename T , typename args >
		struct apply
			: ftmp::id < T >
		{
		} ;
		template < template < typename ... T_ > class func_template , typename ... T , typename args >
		struct apply < func_template < T ... > , args >
			: apply_impl
			<
				func_template < T ... > ,
				typename apply_helper
				<
					ftmp::list < T ... > ,
					args
				>::type
			>
		{
		} ;
	}
	template < typename func >
	struct lambda
	{
		template < typename ... T >
		struct apply
			: ftmp::detail::apply
			<
				func ,
				list < T ... > 
			>::type
		{
		} ;
	} ;
}
#endif