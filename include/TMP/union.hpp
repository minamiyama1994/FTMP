#ifndef TMP_UNION_HPP
#define TMP_UNION_HPP
namespace tmp
{
	template < typename T1 , typename T2 >
	struct union_ ;
}
#include"TMP/list.hpp"
#include"TMP/to_set.hpp"
#include"TMP/set.hpp"
namespace tmp
{
	template < typename ... T1 , typename ... T2 >
	struct union_ < set < T1 ... > , set < T2 ... > >
		: to_set < list < T1 ... , T2 ... > >
	{
	} ;
}
#endif