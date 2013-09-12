#ifndef TMP_UNIQUE_HPP
#define TMP_UNIQUE_HPP
#include"TMP/foldr.hpp"
#include"TMP/elem.hpp"
namespace tmp
{
	template < typename seq >
	struct unique
		: foldr
		<
			eval_if
			<
				elem < arg < 0 > , arg < 1 > > ,
				id < arg < 1 > > ,
				cons < arg < 0 > , arg < 1 > >
			> ,
			list < > ,
			seq
		>
	{
	} ;
}
#endif