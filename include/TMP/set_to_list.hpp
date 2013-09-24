#ifndef TMP_SET_TO_LIST_HPP
#define TMP_SET_TO_LIST_HPP
namespace tmp
{
	template < typename T >
	struct set_to_list ;
}
#include"TMP/list.hpp"
#include"TMP/set.hpp"
#include"TMP/unique.hpp"
namespace tmp
{
	template < typename ... T >
	struct set_to_list < set < T ... > >
		: unique < list < T ... > >
	{
	} ;
}
#endif