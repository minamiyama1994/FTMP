#ifndef TMP_FOLDL_HPP
#define TMP_FOLDL_HPP
namespace tmp
{
	template < typename func , typename a , typename bs >
	struct foldl ;
}
#include"TMP/lambda.hpp"
#include"TMP/tail.hpp"
namespace tmp
{
	template < typename func , typename a >
	struct foldl < func , a , list < > >
	{
		using type = a ;
	} ;
	template < typename func , typename a , typename bs >
	struct foldl
		: foldl
		<
			func ,
			typename tmp::lambda < func >::template apply
			<
				a ,
				typename head < bs >::type
			>::type ,
			typename tail < bs >::type
		>
	{
	} ;
}
#endif