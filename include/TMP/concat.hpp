#ifndef TMP_CONCAT_HPP
#define TMP_CONCAT_HPP
#include"TMP/foldr.hpp"
#include"TMP/append.hpp"
namespace tmp
{
	template < typename seq >
	struct concat
		: foldr
		<
			append < arg < 0 > , arg < 1 > > ,
			list < > ,
			seq
			
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
				concat
				<
					list
					<
						list < char > ,
						list < short , int > ,
						list < long , float , double >
					>
				>::type
			>::type::value ,
			""
		) ;
	}
}
#endif