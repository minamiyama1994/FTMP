#ifndef TMP_NOT_HPP
#define TMP_NOT_HPP
#include"TMP/nand.hpp"
namespace tmp
{
	template < typename T >
	struct not_
		: nand < T , T >
	{
	} ;
}
#endif