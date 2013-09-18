#ifndef TMP_MAP_HPP
#define TMP_MAP_HPP
namespace tmp
{
	template < typename func , typename seq >
	struct map ;
}
#include"TMP/foldr.hpp"
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
}
#endif