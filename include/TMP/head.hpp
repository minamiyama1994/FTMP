#ifndef TMP_HEAD_HPP
#define TMP_HEAD_HPP
namespace tmp
{
	template < typename T >
	struct head ;
}
#include"TMP/list.hpp"
namespace tmp
{
	template < typename T , typename ... T_ >
	struct head < list < T , T_ ... > >
	{
		using type = T ;
	} ;
}
#endif