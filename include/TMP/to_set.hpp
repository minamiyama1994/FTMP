#ifndef TMP_TO_SET_HPP
#define TMP_TO_SET_HPP
namespace tmp
{
	template < typename T >
	struct to_set ;
}
#include"TMP/list.hpp"
#include"TMP/to_set.hpp"
#include"TMP/set.hpp"
#include"TMP/unique.hpp"
namespace tmp
{
	namespace detail
	{
		template < typename T >
		struct to_set_helper ;
		template < typename ... T >
		struct to_set_helper < list < T ... > >
			: set < T ... >
		{
		} ;
	}
	template < typename T >
	struct to_set
		: tmp::detail::to_set_helper < typename unique < T >::type >
	{
	} ;
}
#endif