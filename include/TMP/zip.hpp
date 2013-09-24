#ifndef TMP_ZIP_HPP
#define TMP_ZIP_HPP
namespace tmp
{
	template < typename ... T >
	struct zip ;
}
#include"TMP/any.hpp"
#include"TMP/empty.hpp"
#include"TMP/eval_if.hpp"
#include"TMP/head.hpp"
#include"TMP/list.hpp"
#include"TMP/tail.hpp"
namespace tmp
{
	namespace detail
	{
		template < typename ... T >
		struct variadic_cons
			: tmp::cons
			<
				list < typename head < T >::type ... > ,
				typename zip < typename tail < T >::type ... >::type
			>
		{
		} ;
	}
	template < typename ... T >
	struct zip
		: eval_if
		<
			any < empty < arg < 0 > > , list < T ... > > ,
			list < > ,
			tmp::detail::variadic_cons < T ... >
		>
	{
	} ;
}
#endif