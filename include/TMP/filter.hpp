#ifndef TMP_FILTER_HPP
#define TMP_FILTER_HPP
namespace tmp
{
	template < typename func , typename seq >
	struct filter ;
}
#include"TMP/cons.hpp"
#include"TMP/eval_if.hpp"
#include"TMP/filter.hpp"
#include"TMP/foldr.hpp"
#include"TMP/id.hpp"
#include"TMP/lambda.hpp"
#include"TMP/list.hpp"
#include"TMP/to_set.hpp"
#include"TMP/set.hpp"
namespace tmp
{
	namespace detail
	{
		template < typename func , typename T >
		struct eval_lambda
			: lambda < func >::template apply < T >::type
		{
		} ;
	}
	template < typename func , typename seq >
	struct filter
		: foldr
		<
			eval_if
			<
				tmp::detail::eval_lambda < func , arg < 0 > > ,
				cons < arg < 0 > , arg < 1 > > ,
				id < arg < 1 > >
			> ,
			list < > ,
			seq
		>
	{
	} ;
	template < typename func , typename ... seq >
	struct filter < func , set < seq ... > >
		: to_set
		<
			typename filter
			<
				func ,
				list < seq ... >
			>::type
		>
	{
	} ;
}
#endif