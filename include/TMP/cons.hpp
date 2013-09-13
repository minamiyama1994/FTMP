#ifndef TMP_CONS_HPP
#define TMP_CONS_HPP
#include"TMP/head.hpp"
#include"TMP/tail.hpp"
namespace tmp
{
	template < typename head , typename tail >
	struct cons ;
	template < typename head , typename ... tail >
	struct cons < head , list < tail ... > >
		: list < head , tail ... >
	{
	} ;
}
#endif