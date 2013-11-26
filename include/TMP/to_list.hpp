#ifndef TMP_TO_LIST_HPP
#define TMP_TO_LIST_HPP
namespace tmp
{
	template < typename T >
	struct to_list ;
}
#include"TMP/dict.hpp"
#include"TMP/list.hpp"
#include"TMP/set.hpp"
#include"TMP/unique.hpp"
namespace tmp
{
	template < typename ... T >
	struct to_list < set < T ... > >
		: list < T ... >
	{
	} ;
	template < typename ... T >
	struct to_list < dict < T ... > >
		: list < T ... >
	{
	} ;
}
#endif