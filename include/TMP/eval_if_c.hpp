#ifndef TMP_EVAL_IF_C_HPP
#define TMP_EVAL_IF_C_HPP
namespace tmp
{
	template < bool tf , typename T1 , typename T2 >
	struct eval_if_c ;
}
#include"TMP/if_c.hpp"
namespace tmp
{
	template < bool tf , typename T1 , typename T2 >
	struct eval_if_c
		: if_c
		<
			tf ,
			typename T1::type ,
			typename T2::type
		>
	{
	} ;
}
#endif