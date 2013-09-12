#ifndef TMP_FILTER_HPP
#define TMP_FILTER_HPP
#include"TMP/foldr.hpp"
#include"TMP/cons.hpp"
#include"TMP/eval_if.hpp"
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
	namespace detail
	{
		static_assert
		(
			std::is_same
			<
				list < double , double , double , double , double > ,
				typename filter
				<
					std::is_same < double , arg < 0 > > ,
					list < double , double , int , double , double , double >
				>::type
			>::type::value ,
			"test of \"filter\" failed."
		) ;
	}
}
#endif