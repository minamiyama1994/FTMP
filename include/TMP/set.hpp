#ifndef TMP_SET_HPP
#define TMP_SET_HPP
namespace tmp
{
	template < typename ... T >
	struct set ;
}
#include"TMP/equal.hpp"
#include"TMP/list.hpp"
#include"TMP/size.hpp"
#include"TMP/unique.hpp"
namespace tmp
{
	template < typename ... T >
	struct set
	{
		static_assert
		(
			equal
			<
				typename size
				<
					typename unique
					<
						list < T ... >
					>::type
				>::type ,
				typename size < list < T ... > >::type
			>::type::value ,
			"element is a duplicate."
		) ;
		using type = set ;
	} ;
}
#endif