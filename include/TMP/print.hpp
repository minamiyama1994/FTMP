#ifndef TMP_PRINT_HPP
#define TMP_PRINT_HPP
namespace tmp
{
	template < typename T >
	struct print ;
}
#include"TMP/id.hpp"
namespace tmp
{
	template < typename T >
	struct print
		: id < T >
	{
		template < typename T_ >
		struct always_false
		{
			static constexpr bool value = false ;
		} ;
		static_assert ( always_false < T >::value , "" ) ;
	} ;
}
#endif