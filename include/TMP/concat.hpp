#ifndef TMP_CONCAT_HPP
#define TMP_CONCAT_HPP
#include"TMP/foldr.hpp"
#include"TMP/append.hpp"
namespace tmp
{
	template < typename seq >
	struct concat
		: foldr
		<
			append < arg < 0 > , arg < 1 > > ,
			list < > ,
			seq
		>
	{
	} ;
}
#endif