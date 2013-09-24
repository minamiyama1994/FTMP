#ifndef TMP_UNIQUE_HPP
#define TMP_UNIQUE_HPP
namespace tmp
{
	template < typename seq >
	struct unique ;
}
#include"TMP/cons.hpp"
#include"TMP/equal.hpp"
#include"TMP/eval.hpp"
#include"TMP/filter.hpp"
#include"TMP/foldr.hpp"
#include"TMP/id.hpp"
#include"TMP/list.hpp"
#include"TMP/not.hpp"
#include"TMP/unique.hpp"
namespace tmp
{
	namespace detail
	{
		template < typename T1 , typename T2 >
		struct eval_filter
			: filter
			<
				tmp::not_ < tmp::equal < tmp::arg < 0 > , T1 > > ,
				T2
			>
		{
		} ;
	}
	template < typename seq >
	struct unique
		: foldr
		<
			eval < cons < id < arg < 0 > > , tmp::detail::eval_filter < arg < 0 > , arg < 1 > > > > ,
			list < > ,
			seq
		>
	{
	} ;
}
#endif