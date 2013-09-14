#ifndef TMP_COMPOSITE_HPP
#define TMP_COMPOSITE_HPP
namespace tmp
{
	template < typename func , typename ... funcs >
	struct composite ;
}
#include"TMP/lambda.hpp"
namespace tmp
{
	template < typename func , typename ... funcs >
	struct composite
	{
		template < typename T >
		struct apply
			: lambda < func >::template apply
			<
				typename composite < funcs ... >::template apply < T >::type
			>
		{
		} ;
	} ;
}
#endif