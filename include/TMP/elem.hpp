#ifndef TMP_ELEM_HPP
#define TMP_ELEM_HPP
namespace tmp
{
	template < typename T , typename seq >
	struct elem ;
}
#include"TMP/any.hpp"
#include"TMP/equal.hpp"
namespace tmp
{
	template < typename T , typename seq >
	struct elem
		: any < equal < T , arg < 0 > > , seq >
	{
	} ;
}
#endif