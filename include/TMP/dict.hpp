#ifndef TMP_DICT_HPP
#define TMP_DICT_HPP
namespace tmp
{
	template < typename ... T >
	struct dict ;
}
#include"TMP/at.hpp"
#include"TMP/equal.hpp"
#include"TMP/integral.hpp"
#include"TMP/list.hpp"
#include"TMP/map.hpp"
#include"TMP/size.hpp"
#include"TMP/unique.hpp"
namespace tmp
{
	template < typename ... T >
	struct dict
	{
		static_assert
		(
			equal
			<
				typename size
				<
					typename unique
					<
						typename map
						<
							at < arg < 0 > , integral < int , 0 > > ,
							list < T ... >
						>::type
					>::type
				>::type ,
				typename size < list < T ... > >::type
			>::type::value ,
			"key is a duplicate."
		) ;
		using type = dict ;
	} ;
}
#endif