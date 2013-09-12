#ifndef TMP_ELEM_HPP
#define TMP_ELEM_HPP
#include"TMP/any.hpp"
namespace tmp
{
	template < typename T , typename seq >
	struct elem
		: any < std::is_same < T , arg < 0 > > , seq >
	{
	} ;
}
#endif