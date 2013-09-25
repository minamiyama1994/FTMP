#ifndef TMP_LOOKUP_HPP
#define TMP_LOOKUP_HPP
namespace tmp
{
	template < typename k , typename map >
	struct lookup ;
}
#include"TMP/at.hpp"
#include"TMP/equal.hpp"
#include"TMP/eval.hpp"
#include"TMP/filter.hpp"
#include"TMP/head.hpp"
#include"TMP/id.hpp"
#include"TMP/integral.hpp"
#include"TMP/map.hpp"
#include"TMP/to_list.hpp"
namespace tmp
{
	template < typename k , typename map >
	struct lookup
		: at
		<
			typename head
			<
				typename filter
				<
					eval < equal < id < k > , at < arg < 0 > , integral < int , 0 > > > > ,
					typename to_list < map >::type
				>::type
			>::type ,
			integral < int , 1 >
		>
	{
	} ;
}
#endif