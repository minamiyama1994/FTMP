#ifndef TMP_FOLDR_HPP
#define TMP_FOLDR_HPP
namespace tmp
{
	template < typename func , typename b , typename as >
	struct foldr ;
}
#include"TMP/head.hpp"
#include"TMP/lambda.hpp"
#include"TMP/list.hpp"
#include"TMP/tail.hpp"
namespace tmp
{
	template < typename func , typename b >
	struct foldr < func , b , list < > >
	{
		using type = b ;
	} ;
	template < typename func , typename b , typename as >
	struct foldr
		: lambda < func >::template apply
		<
			typename head < as >::type ,
			typename foldr
			<
				func ,
				b ,
				typename tail < as >::type
			>::type
		>
	{
	} ;
}
#endif