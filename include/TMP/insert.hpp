#ifndef TMP_INSERT_HPP
#define TMP_INSERT_HPP
namespace tmp
{
	template < typename set , typename T >
	struct insert ;
}
#include"TMP/cons.hpp"
#include"TMP/list_to_set.hpp"
#include"TMP/set.hpp"
#include"TMP/set_to_list.hpp"
namespace tmp
{
	template < typename set , typename T >
	struct insert
		: list_to_set
		<
			typename cons
			<
				T ,
				typename set_to_list < set >::type
			>::type
		>
	{
	} ;
}
#endif