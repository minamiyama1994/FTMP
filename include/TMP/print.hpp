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
		: tmp::id < T >
	{
		enum
		{
			n = sizeof ( T ) > -1
		} ; 
	} ;
}
#endif