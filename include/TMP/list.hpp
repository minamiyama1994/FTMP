#ifndef TMP_LIST_HPP
#define TMP_LIST_HPP
namespace tmp
{
	template < typename ... T >
	struct list ;
}
#include"TMP/all.hpp"
#include"TMP/at.hpp"
#include"TMP/equal.hpp"
#include"TMP/eval.hpp"
#include"TMP/size.hpp"
#include"TMP/zip.hpp"
namespace tmp
{
	template < typename ... T >
	struct list
	{
		using type = list ;
	} ;
	template < typename ... T1 >
	struct equal < list < T1 ... > , list < T1 ... > >
		: integral < bool , true >
	{
	} ;
	template < typename ... T1 , typename ... T2 >
	struct equal < list < T1 ... > , list < T2 ... > >
		: and_
		<
			integral
			<
				bool ,
				size < list < T1 ... > >::type::value == size < list < T2 ... > >::type::value
			> ,
			typename all
			<
				eval
				<
					equal
					<
						at < arg < 0 > , integral < int , 0 > > ,
						at < arg < 0 > , integral < int , 1 > >
					>
				> ,
				typename zip < list < T1 ... > , list < T2 ... > >::type
			>::type
		>
	{
	} ;
}
#endif