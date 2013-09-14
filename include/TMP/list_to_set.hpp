#ifndef TMP_LIST_TO_SET_HPP
#define TMP_LIST_TO_SET_HPP
namespace tmp
{
	template < typename T >
	struct list_to_set ;
}
#include"TMP/set.hpp"
#include"TMP/unique.hpp"
namespace tmp
{
	namespace detail
	{
		template < typename T >
		struct list_to_set_helper ;
		template < typename ... T >
		struct list_to_set_helper < list < T ... > >
			: set < T ... >
		{
		} ;
	}
	template < typename T >
	struct list_to_set
		: tmp::detail::list_to_set_helper < typename unique < T >::type >
	{
	} ;
}
#endif