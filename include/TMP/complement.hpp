#ifndef TMP_COMPLEMENT_HPP
#define TMP_COMPLEMENT_HPP
namespace tmp
{
	template < typename T1 , typename T2 >
	struct complement ;
}
#include"TMP/list_to_set.hpp"
namespace tmp
{
	template < typename ... T1 , typename ... T2 >
	struct complement < set < T1 ... > , set < T2 ... > >
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
					id < arg < 1 > > ,
					cons < arg < 0 > , arg < 1 > >
				> ,
				list < > ,
				typename set_to_list < list < T1 ... > >::type
			>::type
		>
	{
	} ;
}
#endif