#ifndef FTMP_HALF_HELPER_HPP
#define FTMP_HALF_HELPER_HPP
namespace ftmp
{
	namespace detail
	{
		template < typename as , typename index_seq >
		struct half_helper ;
	}
}
#include"FTMP/at.hpp"
#include"FTMP/map.hpp"
namespace ftmp
{
	namespace detail
	{
		template < typename as , typename index_seq >
		struct half_helper
			: map
			<
				ftmp::at < as , arg < 0 > > , 
				index_seq
			>
		{
		} ;
	}
}
#endif