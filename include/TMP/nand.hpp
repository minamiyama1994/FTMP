#ifndef TMP_NAND_HPP
#define TMP_NAND_HPP
namespace tmp
{
	template < typename T1 , typename T2 >
	struct nand ;
}
#include"TMP/integral.hpp"
namespace tmp
{
	template < typename T1 , typename T2 >
	struct nand
		: integral < bool , ! ( T1::type::value && T2::type::value ) >
	{
	} ;
}
#endif