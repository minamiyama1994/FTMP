#ifndef TMP_ANY_HPP
#define TMP_ANY_HPP
namespace tmp
{
	template < typename func , typename seq >
	struct any ;
}
#include"TMP/foldl.hpp"
#include"TMP/integral.hpp"
#include"TMP/lambda.hpp"
#include"TMP/or.hpp"
#include"TMP/set.hpp"
namespace tmp
{
	template < typename func , typename seq >
	struct any
		: foldl
		<
			or_ < arg < 0 > , typename lambda < func >::template apply < arg < 1 > > > ,
			integral < bool , false > ,
			seq
		>
	{
	} ;
	template < typename func , typename ... seq >
	struct any < func , set < seq ... > >
		: any
		<
			func ,
			list < seq ... >
		>
	{
	} ;
}
#endif