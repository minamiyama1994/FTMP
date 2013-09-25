#ifndef TMP_TO_LIST_HPP
#define TMP_TO_LIST_HPP
namespace tmp
{
	template < typename T >
	struct to_list ;
}
#include"TMP/list.hpp"
#include"TMP/set.hpp"
#include"TMP/unique.hpp"
namespace tmp
{
	template < typename ... T >
	struct to_list < set < T ... > >
		: unique < list < T ... > >
	{
	} ;
}
#endif