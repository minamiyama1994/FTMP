#ifndef TMP_AT_HPP
#define TMP_AT_HPP
namespace tmp
{
	template < typename T , typename index_type >
	struct at ;
}
#include"TMP/head.hpp"
#include"TMP/integral.hpp"
#include"TMP/tail.hpp"
namespace tmp
{
	namespace detail
	{
		template < typename T , unsigned index >
		struct at_helper ;
		template < typename T , unsigned index >
		struct at_helper
			: at_helper < typename tail < T >::type , index - 1 >
		{
		} ;
		template < typename T >
		struct at_helper < T , 0 >
			: head < T >
		{
		} ;
	}
	template < typename T , typename index_type , index_type index >
	struct at < T , integral < index_type , index > >
		: tmp::detail::at_helper < T , index >
	{
	} ;
}
#endif