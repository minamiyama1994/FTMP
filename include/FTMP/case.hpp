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
#ifndef FTMP_CASE_HPP
#define FTMP_CASE_HPP
namespace ftmp
{
	template < typename T >
	struct case_ ;
	template < typename P , typename R >
	struct match ;
	template < unsigned int N >
	struct pattern ;
}
#include"FTMP/append.hpp"
#include"FTMP/map.hpp"
#include"FTMP/if_c.hpp"
#include"FTMP/size.hpp"
#include"FTMP/foldl.hpp"
#include"FTMP/concat.hpp"
#include"FTMP/list.hpp"
#include"FTMP/integral.hpp"
#include"FTMP/maybe.hpp"
#include"FTMP/print.hpp"
namespace ftmp
{
	namespace detail
	{
		template < typename >
		struct is_one_only ;
		template < typename ... T >
		struct is_one_only < list < T ... > >
			: integral < bool , sizeof ... ( T ) == 1 >
		{
		} ;
		template < typename , typename >
		struct expand_length ;
		template < typename l , typename s , s N >
		struct expand_length < l , integral < s , N > >
			: append
			<
				l ,
				typename map
				<
					id < list < > > ,
					typename make_integer_sequence
					<
						integral < unsigned int , 0 > ,
						integral < unsigned int , N - size < l >::type::value >
					>::type
				>::type
			>
		{
		} ;
		template < typename , typename >
		struct max_value ;
		template < typename T1 , T1 V1 , typename T2 , T2 V2 >
		struct max_value < integral < T1 , V1 > , integral < T2 , V2 > >
			: if_c
			<
				( V1 > V2 ) ,
				integral < T1 , V1 > ,
				integral < T2 , V2 >
			>
		{
		} ;
		template < typename >
		struct max_length ;
		template < typename ... l >
		struct max_length < list < l ... > >
			: foldl
			<
				max_value < arg < 0 > , arg < 1 > > ,
				integral < unsigned int , 0 > ,
				list < typename size < l >::type ... >
			>
		{
		} ;
		template < typename >
		struct set_length ;
		template < typename ... l >
		struct set_length < list < l ... > >
			: map
			<
				expand_length < arg < 0 > , typename max_length < list < l ... > >::type > ,
				list < l ... >
			>
		{
		} ;
		template < typename >
		struct do_zip ;
		template < typename ... T >
		struct do_zip < list < T ... > >
			: zip < T ... >
		{
		} ;
		template < typename , typename >
		struct match_result ;
		template < typename T >
		struct match_result < T , T >
		{
			using type = just < list < > > ;
		} ;
		template < typename T1 , typename T2 >
		struct match_result
		{
			using type = nothing;
		} ;
		template < typename T , unsigned int N >
		struct match_result < T , pattern < N > >
			: id
			<
				just
				<
					typename append
					<
						typename map
						<
							id < list < > > ,
							typename make_integer_sequence < integral < unsigned int , 0 > , integral < unsigned int , N > >::type
						>::type ,
						list < list < T > >
					>::type
				>
			>
		{
		} ;
		template < template < typename ... > class temp , typename ... T , typename ... P >
		struct match_result < temp < T ... > , temp < P ... > >
			: eval_if
			<
				all
				<
					not_
					<
						equal < nothing , arg < 0 > >
					> ,
					list < typename match_result < T , P >::type ... >
				> ,
				eval < map
				<
					id < concat < arg < 0 > > > ,
					eval < do_zip
					<
						eval < set_length
						<
							eval < list
							<
								typename match_result < T , P >::type ...
							> >
						> >
					> >
				> > ,
				id < nothing >
			>
		{
		} ;
		template < typename , typename >
		struct is_match ;
		template < typename T , typename P , typename R >
		struct is_match < T , match < P , R > >
			: eval_if
			<
				equal < nothing , typename match_result < T , P >::type > ,
				id < integral < bool , false > > ,
				eval < all
				<
					id < is_one_only < arg < 0 > > > ,
					typename match_result < T , P >::type
				> >
			>
		{
		} ;
		template < typename , typename >
		struct do_match_impl ;
		template < typename R , typename ... l >
		struct do_match_impl < R , list < l ... > >
			:lambda < R >::template apply
			<
				l ...
			>
		{
		} ;
		template < typename >
		struct replace ;
		template < typename T >
		struct replace
			: id < T >
		{
		} ;
		template < unsigned int N >
		struct replace < pattern < N > >
			: id < arg < N > >
		{
		} ;
		template < template < typename ... > class temp , typename ... T >
		struct replace < temp < T ... > >
			: id < temp < typename replace < T >::type ... > >
		{
		} ;
		template < typename , typename >
		struct do_match ;
		template < typename T , typename P , typename R >
		struct do_match < T , match < P , R > >
			: do_match_impl
			<
				typename replace < R >::type ,
				typename concat
				<
					typename match_result < T , P >::type::type
				>::type
			>
		{
		} ;
	}
	template < typename T >
	struct case_
	{
		template < typename ... PR >
		struct of
			: detail::do_match
			<
				T ,
				typename head
				<
					typename filter
					<
						detail::is_match < T , arg < 0 > > ,
						list < PR ... >
					>::type
				>::type
			>
		{
		} ;
	} ;
	template < typename P , typename R >
	struct match
	{
		using type = match ;
	} ;
	template < unsigned int N >
	struct pattern
	{
		using type = pattern ;
	} ;
}
#endif