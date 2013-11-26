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
						list < T2 ... >
					> ,
					id < arg < 1 > > ,
					cons < arg < 0 > , arg < 1 > >
				> ,
				list < > ,
				list < T1 ... >
			>::type
		>
	{
	} ;
}
#endif