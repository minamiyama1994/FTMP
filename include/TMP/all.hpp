#ifndef TMP_ALL_HPP
#define TMP_ALL_HPP
namespace tmp
{
	template < typename func , typename seq >
	struct all ;
}
#include"TMP/and.hpp"
#include"TMP/foldl.hpp"
#include"TMP/integral.hpp"
#include"TMP/lambda.hpp"
#include"TMP/set.hpp"
namespace tmp
{
	template < typename func , typename seq >
	struct all
		: foldl
		<
			and_ < typename lambda < func >::template apply < arg < 1 > > , arg < 0 > > ,
			integral < bool , true > ,
			seq
		>
	{
	} ;
	template < typename func , typename ... seq >
	struct all < func , set < seq ... > >
		: all
		<
			func ,
			list < seq ... >
		>
	{
	} ;
}
#endif