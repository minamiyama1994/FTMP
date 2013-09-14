#ifndef TMP_EMPTY_HPP
#define TMP_EMPTY_HPP
namespace tmp
{
	template < typename T >
	struct empty ;
}
#include"TMP/foldl.hpp"
#include"TMP/and.hpp"
namespace tmp
{
	template < typename ... T >
	struct empty < list < T ... > >
		: integral < bool , false >
	{
	} ;
	template < >
	struct empty < list < > >
		: integral < bool , true >
	{
	} ;
}
#endif