#ifndef TMP_EQUAL_HPP
#define TMP_EQUAL_HPP
#include"TMP/integral.hpp"
namespace tmp
{
	template < typename T1 , typename T2 >
	struct equal ;
	template < typename T >
	struct equal < T , T >
		: integral < bool , true >
	{
	} ;
	template < typename T1 , typename T2 >
	struct equal
		: integral < bool , false >
	{
	} ;
}
#endif