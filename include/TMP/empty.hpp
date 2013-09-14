#ifndef TMP_EMPTY_HPP
#define TMP_EMPTY_HPP
namespace tmp
{
	template < typename T >
	struct empty ;
}
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