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
		: and_
		<
			typename nand
			<
				typename T1::type ,
				typename T2::type
			>::type ,
			typename or_
			<
				typename T1::type ,
				typename T2::type
			>::type
		>
	{
	} ;
}
#endif