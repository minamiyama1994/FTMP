#ifndef TMP_INSERT_DICT_HPP
#define TMP_INSERT_DICT_HPP
namespace tmp
{
	template < typename k , typename a , typename dict_ >
	struct insert_dict ;
}
#include"TMP/at.hpp"
#include"TMP/dict.hpp"
#include"TMP/equal.hpp"
#include"TMP/eval.hpp"
#include"TMP/filter.hpp"
#include"TMP/id.hpp"
#include"TMP/integral.hpp"
#include"TMP/list.hpp"
#include"TMP/not.hpp"
#include"TMP/to_list.hpp"
namespace tmp
{
	namespace detail
	{
		template < typename k , typename a , typename dict_ >
		struct insert_dict_helper ;
		template < typename k , typename a , typename ... dict_ >
		struct insert_dict_helper < k , a , tmp::list < dict_ ... > >
			: tmp::dict < tmp::list < k , a > , dict_ ... >
		{
		} ;
	}
	template < typename k , typename a , typename dict_ >
	struct insert_dict
		: tmp::detail::insert_dict_helper
		<
			k ,
			a ,
			typename filter
			<
				not_ < eval < equal < at < arg < 0 > , integral < int , 0 > > , id < k > > > > ,
				typename to_list < dict_ >::type
			>::type
		>
	{
	} ;
}
#endif