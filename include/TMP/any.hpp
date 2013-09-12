#ifndef TMP_ANY_HPP
#define TMP_ANY_HPP
#include"TMP/foldl.hpp"
#include"TMP/or.hpp"
namespace tmp
{
	template < typename func , typename seq >
	struct any
		: foldl
		<
			or_ < typename lambda < func >::template apply < arg < 1 > > , arg < 0 > > ,
			bool_ < false > ,
			seq
		>
	{
	} ;
}
#endif