#ifndef TMP_EVAL_IF_HPP
#define TMP_EVAL_IF_HPP
namespace tmp
{
	template < typename tf , typename T1 , typename T2 >
	struct eval_if ;
}
#include"TMP/eval_if_c.hpp"
namespace tmp
{
	template < typename tf , typename T1 , typename T2 >
	struct eval_if
		: eval_if_c
		<
			tf::type::value ,
			T1 ,
			T2
		>
	{
	} ;
}
#endif