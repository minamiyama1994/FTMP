#ifndef TMP_CONCAT_HPP
#define TMP_CONCAT_HPP
#include"TMP/foldr.hpp"
#include"TMP/cons.hpp"
namespace tmp
{
	template < typename seq1 , typename seq2 >
	struct concat
		: foldr
		<
			cons < arg < 0 > , arg < 1 > > ,
			seq2 ,
			seq1
			
		>
	{
	} ;
}
#endif