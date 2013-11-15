#ifndef TMP_NOT_HPP
#define TMP_NOT_HPP
namespace tmp
{
	template < typename T >
	struct not_ ;
}	
#include"TMP/nand.hpp"
namespace tmp
{
	template < typename T >
	struct not_
		: nand
		<
			typename T::type ,
			typename T::type
		>
	{
	} ;
}
#endif