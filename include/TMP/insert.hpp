#ifndef TMP_INSERT_HPP
#define TMP_INSERT_HPP
namespace tmp
{
	template < typename set , typename T >
	struct insert ;
}
#include"TMP/cons.hpp"
#include"TMP/list.hpp"
#include"TMP/to_list.hpp"
#include"TMP/to_set.hpp"
namespace tmp
{
	template < typename set , typename T >
	struct insert
		: to_set
		<
			typename cons
			<
				T ,
				typename to_list < set >::type
			>::type
		>
	{
	} ;
}
#endif