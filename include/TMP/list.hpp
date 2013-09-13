#ifndef TMP_LIST_HPP
#define TMP_LIST_HPP
#include"TMP/integral.hpp"
#include"TMP/size.hpp"
namespace tmp
{
	template < typename ... T >
	struct list
	{
		using type = list ;
	} ;
	template < typename ... T >
	struct size < list < T ... > >
		: integral < decltype ( sizeof ... ( T ) ) , sizeof ... ( T ) >
	{
	} ;
}
#endif