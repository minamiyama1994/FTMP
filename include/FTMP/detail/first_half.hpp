#ifndef FTMP_FIRST_HALF_HPP
#define FTMP_FIRST_HALF_HPP
namespace ftmp
{
	namespace detail
	{
		template < typename as >
		struct first_half ;
	}
}
#include"FTMP/integral.hpp"
#include"FTMP/list.hpp"
#include"FTMP/make_integer_sequence.hpp"
#include"FTMP/detail/half_helper.hpp"
namespace ftmp
{
	namespace detail
	{
		template < typename ... as >
		struct first_half < list < as ... > >
			: half_helper
			<
				list < as ... > ,
				typename make_integer_sequence
				<
					integral < decltype ( sizeof ... ( as ) ) , 0 > ,
					integral < decltype ( sizeof ... ( as ) ) , sizeof ... ( as ) / 2 >
				>::type
			>
		{
		} ;
	}
}
#endif