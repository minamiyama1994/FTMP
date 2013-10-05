#ifndef TMP_SIZE_HPP
#define TMP_SIZE_HPP
namespace tmp
{
	template < typename T >
	struct size ;
}
#include"TMP/integral.hpp"
#include"TMP/list.hpp"
#include"TMP/set.hpp"
#include"TMP/to_list.hpp"
namespace tmp
{
	template < typename ... T >
	struct size < list < T ... > >
		: integral < decltype ( sizeof ... ( T ) ) , sizeof ... ( T ) >
	{
	} ;
	template < typename ... T >
	struct size < set < T ... > >
		: size < typename to_list < set < T ... > >::type >
	{
	} ;
}
#endif