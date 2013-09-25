#ifndef TMP_COMPLEMENT_HPP
#define TMP_COMPLEMENT_HPP
namespace tmp
{
	template < typename T1 , typename T2 >
	struct complement ;
}
#include"TMP/cons.hpp"
#include"TMP/elem.hpp"
#include"TMP/eval_if.hpp"
#include"TMP/foldr.hpp"
#include"TMP/id.hpp"
#include"TMP/list.hpp"
#include"TMP/to_set.hpp"
#include"TMP/set.hpp"
#include"TMP/to_list.hpp"
namespace tmp
{
	template < typename ... T1 , typename ... T2 >
	struct complement < set < T1 ... > , set < T2 ... > >
		: to_set
		<
			typename foldr
			<
				eval_if
				<
					elem
					<
						arg < 0 > ,
						typename to_list < list < T2 ... > >::type
					> ,
					id < arg < 1 > > ,
					cons < arg < 0 > , arg < 1 > >
				> ,
				list < > ,
				typename to_list < list < T1 ... > >::type
			>::type
		>
	{
	} ;
}
#endif