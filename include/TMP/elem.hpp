#ifndef TMP_ELEM_HPP
#define TMP_ELEM_HPP
#include"TMP/foldl.hpp"
#include"TMP/or.hpp"
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
	template < typename T , typename seq >
	struct elem
		: foldl
		<
			or_ < std::is_same < T , arg < 1 > > , arg < 0 > > ,
			bool_ < false > ,
			seq
		>
	{
	} ;
	namespace detail
	{
		static_assert
		(
			elem
			<
				int
				list < char , short , int , long , float , double >
			>::type::value ,
			"test of \"concat\" failed."
		) ;
		static_assert
		(
			! elem
			<
				unsigned char
				list < char , short , int , long , float , double >
			>::type::value ,
			"test of \"concat\" failed."
		) ;
	}
}
#endif