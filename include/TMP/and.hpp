#ifndef TMP_AND_HPP
#define TMP_AND_HPP
namespace tmp
{
	template < typename T1 , typename T2 >
	struct and_ ;
}
#include"TMP/nand.hpp"
#include"TMP/not.hpp"
namespace tmp
{
	template < typename T1 , typename T2 >
	struct and_
		: not_ < nand < T1 , T2 > >
	{
	} ;
}
#endif