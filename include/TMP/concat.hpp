#ifndef TMP_CONCAT_HPP
#define TMP_CONCAT_HPP
namespace tmp
{
	template < typename seq >
	struct concat ;
}
#include"TMP/append.hpp"
#include"TMP/foldr.hpp"
#include"TMP/list.hpp"
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