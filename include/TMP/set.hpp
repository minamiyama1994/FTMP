#ifndef TMP_SET_HPP
#define TMP_SET_HPP
namespace tmp
{
	template < typename ... T >
	struct set ;
}
#include"TMP/all.hpp"
#include"TMP/elem.hpp"
#include"TMP/equal.hpp"
#include"TMP/size.hpp"
#include"TMP/set_to_list.hpp"
namespace tmp
{
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
	template < typename ... T >
	struct set
	{
		using type = set ;
	} ;
	template < typename ... T1 , typename ... T2 >
	struct equal < set < T1 ... > , set < T2 ... > >
		: foldl
		<
			and_
			<
				arg < 0 > ,
				elem < arg < 1 > , typename set_to_list < set < T2 ... > >::type >
			> ,
			integral < bool , true > ,
			typename set_to_list < set < T1 ... > >::type
		>
	{
	} ;
	template < typename ... T >
	struct size < set < T ... > >
		: size < set_to_list < set < T ... > > >
	{
	} ;
}
#endif