#ifndef TMP_CONS_HPP
#define TMP_CONS_HPP
namespace tmp
{
	template < typename head , typename tail >
	struct cons ;
}
#include"TMP/list.hpp"
namespace tmp
{
	template < typename head , typename ... tail >
	struct cons < head , list < tail ... > >
		: list < head , tail ... >
	{
	} ;
}
#endif