#ifndef TMP_MAP_HPP
#define TMP_MAP_HPP
namespace tmp
{
	template < typename func , typename seq >
	struct map ;
}
#include"TMP/cons.hpp"
#include"TMP/eval.hpp"
#include"TMP/foldr.hpp"
#include"TMP/id.hpp"
#include"TMP/lambda.hpp"
#include"TMP/list.hpp"
#include"TMP/list_to_set.hpp"
#include"TMP/set.hpp"
#include"TMP/set_to_list.hpp"
namespace tmp
{
	template < typename func , typename seq >
	struct map
		: foldr
		<
			eval
			<
				cons
				<
					typename lambda < func >::template apply < arg < 0 > > ,
					id < arg < 1 > >
				>
			> ,
			list < > ,
			seq
		>
	{
	} ;
	template < typename func , typename ... seq >
	struct map < func , set < seq ... > >
		: list_to_set
		<
			typename map
			<
				func ,
				typename set_to_list < set < seq ... > >::type
			>::type
		>
	{
	} ;
}
#endif