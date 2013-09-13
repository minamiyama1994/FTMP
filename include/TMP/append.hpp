#ifndef TMP_APPEND_HPP
#define TMP_APPEND_HPP
#include"TMP/list.hpp"
namespace tmp
{
	template < typename L1 , typename L2 >
	struct append ;
	template < typename ... L1 , typename ... L2 >
	struct append < list < L1 ... > , list < L2 ... > >
		: list < L1 ... , L2 ... >
	{
	} ;
}
#endif