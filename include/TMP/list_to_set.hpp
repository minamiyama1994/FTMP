#ifndef TMP_LIST_TO_SET_HPP
#define TMP_LIST_TO_SET_HPP
#include"TMP/set.hpp"
#include"TMP/unique.hpp"
namespace tmp
{
	template < typename T >
	struct list_to_set ;
	template < typename T >
	struct list_to_set_helper ;
	template < typename T >
	struct list_to_set
		: list_to_set_helper < typename unique < T >::type >
	{
	} ;
	template < typename ... T >
	struct list_to_set_helper < list < T ... > >
		: set < T ... >
	{
	} ;
}
#endif