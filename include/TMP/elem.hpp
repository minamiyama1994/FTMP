#ifndef TMP_ELEM_HPP
#define TMP_ELEM_HPP
#include"TMP/any.hpp"
namespace tmp
{
	template < typename T , typename seq >
	struct elem
		: any < std::is_same < T , arg < 0 > > , seq >
	{
	} ;
	namespace detail
	{
		static_assert
		(
			elem
			<
				int ,
				list < char , short , int , long , float , double >
			>::type::value ,
			"test of \"concat\" failed."
		) ;
		static_assert
		(
			! elem
			<
				unsigned char ,
				list < char , short , int , long , float , double >
			>::type::value ,
			"test of \"elem\" failed."
		) ;
	}
}
#endif