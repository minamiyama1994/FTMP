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
#ifndef FTMP_TYPED_MAP_HPP
#define FTMP_TYPED_MAP_HPP
namespace ftmp
{
	template < typename ... T >
	class typed_map ;
}
#include<utility>
#include"FTMP/at.hpp"
#include"FTMP/equal.hpp"
#include"FTMP/integral.hpp"
#include"FTMP/list.hpp"
#include"FTMP/map.hpp"
#include"FTMP/size.hpp"
#include"FTMP/unique.hpp"
namespace ftmp
{
	template < typename k , typename a >
	class typed_map < list < k , a > >
	{
		a value_ ;
	public :
		typed_map ( ) = default ;
		typed_map ( const typed_map & ) = default ;
		typed_map ( typed_map && ) = default ;
		auto operator = ( const typed_map & ) -> typed_map & = default ;
		auto operator = ( typed_map && ) -> typed_map & = default ;
		~ typed_map ( ) = default ;
		typed_map ( const a & value ) ;
		typed_map ( a && value ) ;
		auto value ( ) const -> const a & ;
		auto value ( ) -> a & ;
		auto value ( const a & value ) -> void ;
		auto value ( a && value ) -> void ;
	} ;
	template < typename k , typename a , typename ... T >
	class typed_map < list < k , a > , T ... >
		: public typed_map < T ... >
	{
		static_assert
		(
			equal
			<
				typename size
				<
					typename unique
					<
						typename map
						<
							at < arg < 0 > , integral < int , 0 > > ,
							list < list < k , a > , T ... >
						>::type
					>::type
				>::type ,
				typename size < list < list < k , a > , T ... > >::type
			>::type::value ,
			"key is a duplicate."
		) ;
		a value_ ;
	public :
		typed_map ( ) = default ;
		typed_map ( const typed_map & ) = default ;
		typed_map ( typed_map && ) = default ;
		auto operator = ( const typed_map & ) -> typed_map & = default ;
		auto operator = ( typed_map && ) -> typed_map & = default ;
		~ typed_map ( ) = default ;
		template < typename ... T_ >
		typed_map ( const a & value , const T_ & ... t ) ;
		template < typename ... T_ >
		typed_map ( a && value , T_ && ... t ) ;
		auto value ( ) const -> const a & ;
		auto value ( ) -> a & ;
		auto value ( const a & value ) -> void ;
		auto value ( a && value ) -> void ;
	} ;
	template < typename k , typename a >
	typed_map < list < k , a > >::typed_map ( const a & value )
		: value_ ( value )
	{
	}
	template < typename k , typename a >
	typed_map < list < k , a > >::typed_map ( a && value )
		: value_ ( std::move ( value ) )
	{
	}
	template < typename k , typename a >
	auto typed_map < list < k , a > >::value ( ) const -> const a &
	{
		return value_ ;
	}
	template < typename k , typename a >
	auto typed_map < list < k , a > >::value ( ) -> a &
	{
		return value_ ;
	}
	template < typename k , typename a >
	auto typed_map < list < k , a > >::value ( const a & value ) -> void
	{
		value_ = value ;
	}
	template < typename k , typename a >
	auto typed_map < list < k , a > >::value ( a && value ) -> void
	{
		value_ = std::move ( value ) ;
	}
	template < typename k , typename a , typename ... T >
	template < typename ... T_ >
	typed_map < list < k , a > , T ... >::typed_map ( const a & value , const T_ & ... t )
		: typed_map < T ... > ( t ... )
		, value_ ( value )
	{
	}
	template < typename k , typename a , typename ... T >
	template < typename ... T_ >
	typed_map < list < k , a > , T ... >::typed_map ( a && value , T_ && ... t )
		: typed_map < T ... > ( std::move ( t ) ... )
		, value_ ( std::move ( value ) )
	{
	}
	template < typename k , typename a , typename ... T >
	auto typed_map < list < k , a > , T ... >::value ( ) const -> const a &
	{
		return value_ ;
	}
	template < typename k , typename a , typename ... T >
	auto typed_map < list < k , a > , T ... >::value ( ) -> a &
	{
		return value_ ;
	}
	template < typename k , typename a , typename ... T >
	auto typed_map < list < k , a > , T ... >::value ( const a & value ) -> void
	{
		value_ = value ;
	}
	template < typename k , typename a , typename ... T >
	auto typed_map < list < k , a > , T ... >::value ( a && value ) -> void
	{
		value_ = std::move ( value ) ;
	}
	template < bool is_equal , typename k , typename k_ , typename a , typename ... T >
	struct get_helper ;
	template < typename k , typename k_ , typename a , typename ... T >
	auto get ( const typed_map < list < k_ , a > , T ... > & map ) -> decltype ( get_helper < equal < k , k_ >::type::value , k , k_ , a , T ... >::func ( map ) )
	{
		return get_helper < equal < k , k_ >::type::value , k , k_ , a , T ... >::func ( map ) ;
	}
	template < typename k , typename k_ , typename a , typename ... T >
	auto get ( typed_map < list < k_ , a > , T ... > & map ) -> decltype ( get_helper < equal < k , k_ >::type::value , k , k_ , a , T ... >::func ( map ) )
	{
		return get_helper < equal < k , k_ >::type::value , k , k_ , a , T ... >::func ( map ) ;
	}
	template < typename k , typename k_ , typename a , typename ... T >
	struct get_helper < true , k , k_ , a , T ... >
	{
		static auto func ( const typed_map < list < k_ , a > , T ... > & map ) -> const a &
		{
			return map.value ( ) ;
		}
		static auto func ( typed_map < list < k_ , a > , T ... > & map ) -> a &
		{
			return map.value ( ) ;
		}
	} ;
	template < typename k , typename k_ , typename a , typename ... T >
	struct get_helper < false , k , k_ , a , T ... >
	{
		static auto func ( const typed_map < list < k_ , a > , T ... > & map ) -> decltype ( get < k > ( static_cast < const typed_map < T ... > & > ( map ) ) )
		{
			return get < k > ( static_cast < const typed_map < T ... > & > ( map ) ) ;
		}
		static auto func ( typed_map < list < k_ , a > , T ... > & map ) -> decltype ( get < k > ( static_cast < typed_map < T ... > & > ( map ) ) )
		{
			return get < k > ( static_cast < typed_map < T ... > & > ( map ) ) ;
		}
	} ;
}
#endif