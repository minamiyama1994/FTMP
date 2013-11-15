#ifndef TMP_OR_HPP
#define TMP_OR_HPP
namespace tmp
{
	template < typename T1 , typename T2 >
	struct or_ ;
}
#include"TMP/nand.hpp"
#include"TMP/not.hpp"
namespace tmp
{
	template < typename T1 , typename T2 >
	struct or_
		: nand
		<
			typename not_
			<
				typename T1::type
			>::type ,
			typename not_
			<
				typename T2::type
			>::type
		>
	{
	} ;
}
#endif