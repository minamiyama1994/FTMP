#ifndef TMP_EMPTY_HPP
#define TMP_EMPTY_HPP
#include"TMP/foldl.hpp"
#include"TMP/and.hpp"
namespace tmp
{
	template < typename T >
	struct empty
		: foldl
		<
			and_ < integral < bool , false > , arg < 0 > > ,
			integral < bool , true > ,
			T
		>
	{
	} ;
}
#endif