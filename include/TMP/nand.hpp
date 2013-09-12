#ifndef TMP_NAND_HPP
#define TMP_NAND_HPP
#include"TMP/bool.hpp"
namespace tmp
{
	template < typename T1 , typename T2 >
	struct nand
		: bool_ < ! ( T1::type::value && T2::type::value ) >
	{
	} ;
}
#endif