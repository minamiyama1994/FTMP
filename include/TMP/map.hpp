#ifndef TMP_MAP_HPP
#define TMP_MAP_HPP
#include"TMP/foldr.hpp"
#include"TMP/cons.hpp"
#include"TMP/id.hpp"
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
	namespace detail
	{
		static_assert
		(
			std::is_same
			<
				list < char , short , int , long , float , double > ,
				typename map
				<
					tmp::id < tmp::arg < 0 > > ,
					list < char , short , int , long , float , double >
				>::type
			>::type::value ,
			"test of \"map\" failed."
		) ;
	}
}
#endif