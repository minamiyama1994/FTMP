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
#include"TMP/set_to_list.hpp"
namespace tmp
{
	template < typename ... T >
	struct set
	{
		using type = set ;
	} ;
	template < typename ... T1 , typename ... T2 >
	struct equal < set < T1 ... > , set < T2 ... > >
		: and_
		<
			typename foldl
			<
				and_
				<
					arg < 0 > ,
					elem < arg < 1 > , typename set_to_list < set < T2 ... > >::type >
				> ,
				integral < bool , true > ,
				typename set_to_list < set < T1 ... > >::type
			>::type ,
			typename foldl
			<
				and_
				<
					arg < 0 > ,
					elem < arg < 1 > , typename set_to_list < set < T1 ... > >::type >
				> ,
				integral < bool , true > ,
				typename set_to_list < set < T2 ... > >::type
			>::type
		>
	{
	} ;
}
#endif