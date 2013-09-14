#ifndef TMP_ANY_HPP
#define TMP_ANY_HPP
namespace tmp
{
	template < typename func , typename seq >
	struct any ;
}
#include"TMP/foldl.hpp"
#include"TMP/or.hpp"
namespace tmp
{
	template < typename func , typename seq >
	struct any
		: foldl
		<
			or_ < arg < 0 > , typename lambda < func >::template apply < arg < 1 > > > ,
			integral < bool , false > ,
			seq
		>
	{
	} ;
}
#endif