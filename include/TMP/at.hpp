#ifndef TMP_AT_HPP
#define TMP_AT_HPP
#include"TMP/head.hpp"
#include"TMP/tail.hpp"
#include"TMP/integral.hpp"
namespace tmp
{
	template < typename T , typename index >
	struct at ;
	template < typename T , typename index_type , index_type index >
	struct at < T , integral < index_type , index > >
		: at < typename tail < T >::type , integral < index_type , index - 1 > >
	{
	} ;
	template < typename T , typename index_type >
	struct at < T , integral < index_type , 0 > >
		: head < T >
	{
	} ;
}
#endif