#ifndef TMP_SYMMETRIC_DIFFERENCE_HPP
#define TMP_SYMMETRIC_DIFFERENCE_HPP
namespace tmp
{
	template < typename T1 , typename T2 >
	struct symmetric_difference ;
}
#include"TMP/complement.hpp"
#include"TMP/set.hpp"
#include"TMP/union.hpp"
namespace tmp
{
	template < typename ... T1 , typename ... T2 >
	struct symmetric_difference < set < T1 ... > , set < T2 ... > >
		: union_
		<
			typename complement < set < T1 ... > , set < T2 ... > >::type ,
			typename complement < set < T2 ... > , set < T1 ... > >::type
		>
	{
	} ;
}
#endif