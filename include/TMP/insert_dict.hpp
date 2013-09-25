#ifndef TMP_INSERT_DICT_HPP
#define TMP_INSERT_DICT_HPP
namespace tmp
{
	template < typename k , typename a , typename dict_ >
	struct insert_dict ;
}
#include"TMP/dict.hpp"
#include"TMP/list.hpp"
namespace tmp
{
	template < typename k , typename a , typename ... dict_ >
	struct insert_dict < k , a , dict < dict_ ... > >
		: dict < list < k , a > , dict_ ... >
	{
	} ;
}
#endif