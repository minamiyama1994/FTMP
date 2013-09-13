#ifndef TMP_TAIL_HPP
#define TMP_TAIL_HPP
#include"TMP/list.hpp"
namespace tmp
{
	template < typename T >
	struct tail ;
	template < typename T , typename ... T_ >
	struct tail < list < T , T_ ... > >
		: list < T_ ... >
	{
	} ;
}
#endif