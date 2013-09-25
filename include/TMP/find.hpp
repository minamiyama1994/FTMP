#ifndef TMP_FIND_HPP
#define TMP_FIND_HPP
namespace tmp
{
	template < typename k , typename map >
	struct find ;
}
#include"TMP/at.hpp"
#include"TMP/equal.hpp"
#include"TMP/eval.hpp"
#include"TMP/filter.hpp"
#include"TMP/id.hpp"
#include"TMP/integral.hpp"
#include"TMP/map.hpp"
#include"TMP/size.hpp"
#include"TMP/to_list.hpp"
namespace tmp
{
	template < typename k , typename map >
	struct find
		: integral
		<
			bool ,
			size
			<
				typename filter
				<
					eval < equal < id < k > , at < arg < 0 > , integral < int , 0 > > > > ,
					typename to_list < map >::type
				>::type
			>::type::value != 0
		>
	{
	} ;
}
#endif