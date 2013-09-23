#ifndef TMP_INTERSECTION_HPP
#define TMP_INTERSECTION_HPP
namespace tmp
{
	template < typename T1 , typename T2 >
	struct intersection ;
}
#include"TMP/list_to_set.hpp"
namespace tmp
{
	template < typename ... T1 , typename ... T2 >
	struct intersection < set < T1 ... > , set < T2 ... > >
		: list_to_set
		<
			typename foldr
			<
				eval_if
				<
					elem
					<
						arg < 0 > ,
						typename set_to_list < list < T2 ... > >::type
					> ,
					cons < arg < 0 > , arg < 1 > > ,
					id < arg < 1 > >
				> ,
				list < > ,
				typename set_to_list < list < T1 ... > >::type
			>::type
		>
	{
	} ;
}
#endif