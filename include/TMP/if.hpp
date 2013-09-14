#ifndef TMP_IF_HPP
#define TMP_IF_HPP
namespace tmp
{
	template < typename tf , typename T1 , typename T2 >
	struct if_ ;
}
#include"TMP/if_c.hpp"
namespace tmp
{
	template < typename tf , typename T1 , typename T2 >
	struct if_
		: if_c
		<
			tf::type::value ,
			T1 ,
			T2
		>
	{
	} ;
}
#endif