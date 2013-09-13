#ifndef TMP_MAP_HPP
#define TMP_MAP_HPP
#include"TMP/foldr.hpp"
namespace tmp
{
	namespace detail
	{
		template < typename T1 , typename T2 >
		struct eval_cons
			: tmp::cons < typename T1::type , typename T2::type >
		{
		} ;
	}
	template < typename func , typename seq >
	struct map
		: foldr
		<
			tmp::detail::eval_cons
			<
				typename lambda < func >::template apply < arg < 0 > > ,
				id < arg < 1 > >
			> ,
			list < > ,
			seq
		>
	{
	} ;
}
#endif