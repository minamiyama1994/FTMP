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
		: not_
		<
			typename nand
			<
				typename T1::type ,
				typename T2::type
			>::type
		>
	{
	} ;
}
#endif