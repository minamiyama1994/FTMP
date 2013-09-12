#ifndef TMP_UNIQUE_HPP
#define TMP_UNIQUE_HPP
#include"TMP/foldr.hpp"
#include"TMP/elem.hpp"
namespace tmp
{
	namespace detail
	{
		template < typename T , typename Ts >
		struct eval_elem
			: elem < typename T::type , typename Ts::type >
		{
		} ;
	}
	template < typename seq >
	struct unique
		: foldr
		<
			eval_if
			<
				tmp::detail::eval_elem < arg < 0 > , arg < 1 > > ,
				id < arg < 1 > > ,
				cons < arg < 0 > , arg < 1 > >
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
				list < char , short , long , int , float , double > ,
				typename unique
				<
					list < char , short , int , long , int , float , double >
				>::type
			>::type::value ,
			"test of \"concat\" failed."
		) ;
	}
}
#endif