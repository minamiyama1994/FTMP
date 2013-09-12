#ifndef TMP_OR_HPP
#define TMP_OR_HPP
#include"TMP/not.hpp"
namespace tmp
{
	template < typename T1 , typename T2 >
	struct or_
		: nand < not_ < T1 > , not_ < T2 > >
	{
	} ;
}
#endif