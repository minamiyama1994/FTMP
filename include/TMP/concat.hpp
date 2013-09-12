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
	namespace detail
	{
		static_assert
		(
			std::is_same
			<
				list < char , short , int , long , float , double > ,
				typename concat
				<
					list < char , short , int > ,
					list < long , float , double >
				>::type
			>::type::value ,
			"test of \"concat\" failed."
		) ;
	}
}
#endif