#ifndef FTMP_SECOND_HALF_HPP
#define FTMP_SECOND_HALF_HPP
namespace ftmp
{
	namespace detail
	{
		template < typename as >
		struct second_half ;
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
		struct second_half < ftmp::list < as ... > >
			: half_helper
			<
				ftmp::list < as ... > ,
				typename ftmp::make_integer_sequence
				<
					ftmp::integral < decltype ( sizeof ... ( as ) ) , sizeof ... ( as ) / 2 > ,
					ftmp::integral < decltype ( sizeof ... ( as ) ) , sizeof ... ( as ) >
				>::type
			>
		{
		} ;
	}
}
#endif