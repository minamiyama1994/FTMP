#ifndef TMP_DELETE_HPP
#define TMP_DELETE_HPP
namespace tmp
{
	template < typename k , typename map >
	struct delete_ ;
}
#include"TMP/at.hpp"
#include"TMP/equal.hpp"
#include"TMP/eval.hpp"
#include"TMP/filter.hpp"
#include"TMP/id.hpp"
#include"TMP/integral.hpp"
#include"TMP/map.hpp"
#include"TMP/not.hpp"
#include"TMP/to_list.hpp"
#include"TMP/to_dict.hpp"
namespace tmp
{
	template < typename k , typename map >
	struct delete_
		: to_dict
		<
			typename filter
			<
				not_ < eval < equal < id < k > , at < arg < 0 > , integral < int , 0 > > > > > ,
				typename to_list < map >::type
			>::type
		>
	{
	} ;
}
#endif