#ifndef TMP_TO_DICT_HPP
#define TMP_TO_DICT_HPP
namespace tmp
{
	template < typename T >
	struct to_dict ;
}
#include"TMP/at.hpp"
#include"TMP/dict.hpp"
#include"TMP/eval.hpp"
#include"TMP/foldr.hpp"
#include"TMP/id.hpp"
#include"TMP/insert.hpp"
#include"TMP/integral.hpp"
namespace tmp
{
	template < typename ... T >
	struct to_dict < list < T ... > >
		: foldr
		<
			eval < insert
			<
				at < arg < 0 > , integral < int , 0 > > ,
				at < arg < 0 > , integral < int , 1 > > ,
				id < arg < 1 > >
			> > ,
			dict < > ,
			list < T ... >
		>
	{
	} ;
}
#endif