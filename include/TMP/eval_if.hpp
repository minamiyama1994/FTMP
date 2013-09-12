#ifndef TMP_EVAL_IF_HPP
#define TMP_EVAL_IF_HPP
#include"TMP/if.hpp"
namespace tmp
{
	template < typename tf , typename T1 , typename T2 >
	struct eval_if
		: if_
		<
			tf ,
			typename T1::type ,
			typename T2::type
		>
	{
	} ;
}
#endif