#ifndef TMP_HEAD_HPP
#define TMP_HEAD_HPP
#include"TMP/list.hpp"
namespace tmp
{
	template < typename T >
	struct head ;
	template < typename T , typename ... T_ >
	struct head < list < T , T_ ... > >
	{
		using type = T ;
	} ;
}
#endif