#ifndef TMP_FOLDR_HPP
#define TMP_FOLDR_HPP
#include"TMP/list.hpp"
#include"TMP/lambda.hpp"
namespace tmp
{
	template < typename func , typename b , typename as >
	struct foldr ;
	template < typename func , typename b >
	struct foldr < func , b , list < > >
	{
		using type = b ;
	} ;
	template < typename func , typename b , typename a0 , typename ... a >
	struct foldr < func , b , list < a0 , a ... > >
		: tmp::lambda < func >::template apply
		<
			a0 ,
			typename foldr
			<
				func ,
				b ,
				list < a ... >
			>::type
		>
	{
	} ;
}
#endif