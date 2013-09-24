#ifndef TMP_XOR_HPP
#define TMP_XOR_HPP
namespace tmp
{
	template < typename T1 , typename T2 >
	struct xor_ ;
}
#include"TMP/and.hpp"
#include"TMP/nand.hpp"
#include"TMP/or.hpp"
namespace tmp
{
	template < typename T1 , typename T2 >
	struct xor_
		: and_ < nand < T1 , T2 > , or_ < T1 , T2 > >
	{
	} ;
}
#endif