#ifndef TMP_SIZE_HPP
#define TMP_SIZE_HPP
#include"TMP/list.hpp"
#include"TMP/integral.hpp"
namespace tmp
{
	template < typename T >
	struct size ;
	template < typename ... T >
	struct size < list < T ... > >
		: integral < decltype ( sizeof ... ( T ) ) , sizeof ... ( T ) >
	{
	} ;
}
#endif