#ifndef TMP_SET_HPP
#define TMP_SET_HPP
namespace tmp
{
	template < typename ... T >
	struct set ;
}
#include"TMP/and.hpp"
#include"TMP/elem.hpp"
#include"TMP/equal.hpp"
#include"TMP/foldl.hpp"
#include"TMP/integral.hpp"
#include"TMP/set_to_list.hpp"
namespace tmp
{
	template < typename ... T >
	struct set
	{
		using type = set ;
	} ;
}
#endif