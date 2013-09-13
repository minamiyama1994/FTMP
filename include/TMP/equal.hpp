#ifndef TMP_EQUAL_HPP
#define TMP_EQUAL_HPP
#include"TMP/all.hpp"
#include"TMP/size.hpp"
#include"TMP/zip.hpp"
namespace tmp
{
	template < typename T1 , typename T2 >
	struct equal ;
	namespace detail
	{
		template < typename T1 , typename T2 >
		struct eval_equal
			: equal < typename T1::type , typename T2::type >
		{
		} ;
		template < typename T >
		struct all_equal
			: all
			<
				eval_equal
				<
					at < arg < 0 > , integral < int , 0 > > ,
					at < arg < 0 > , integral < int , 1 > >
				> ,
				T
			>
		{
		} ;
	}
	template < typename T >
	struct equal < T , T >
		: integral < bool , true >
	{
	} ;
	template < typename T1 , typename T2 >
	struct equal
		: integral < bool , false >
	{
	} ;
	template < typename ... T1 , typename ... T2 >
	struct equal < list < T1 ... > , list < T2 ... > >
		: and_
		<
			integral
			<
				bool ,
				size < list < T1 ... > >::type::value == size < list < T2 ... > >::type::value
			> ,
			all
			<
				tmp::detail::all_equal < arg < 0 > > ,
				typename zip < list < T1 ... > , list < T2 ... > >::type
			>
		>
	{
	} ;
}
#endif