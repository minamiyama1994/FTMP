#ifndef TMP_FOLDL_HPP
#define TMP_FOLDL_HPP
#include"TMP/list.hpp"
#include"TMP/lambda.hpp"
namespace tmp
{
	template < typename func , typename a , typename bs >
	struct foldl ;
	template < typename func , typename a >
	struct foldl < func , a , list < > >
	{
		using type = a ;
	} ;
	template < typename func , typename a , typename b0 , typename ... b >
	struct foldl < func , a , list < b0 , b ... > >
		: foldl
		<
			func ,
			typename tmp::function::lambda < func >::template apply
			<
				a ,
				b0
			>::type ,
			list < b ... >
		>
	{
	} ;
}
#endif