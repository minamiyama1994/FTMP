#ifndef TMP_INSERT_HPP
#define TMP_INSERT_HPP
namespace tmp
{
	template < typename T , typename set >
	struct insert ;
}
#include"TMP/set.hpp"
#include"TMP/union.hpp"
namespace tmp
{
	template < typename T , typename set >
	struct insert
		: union_
		<
			tmp::set < T > ,
			set
		>
	{
	} ;
}
#endif