#ifndef TMP_LAST_HPP
#define TMP_LAST_HPP
namespace tmp
{
	template < typename T >
	struct last ;
}
#include"TMP/tail.hpp"
namespace tmp
{
	template < typename T >
	struct last
		: last < typename tail < T >::type >
	{
	} ;
	template < typename T >
	struct last < list < T > >
		: id < T >
	{
	} ;
}
#endif