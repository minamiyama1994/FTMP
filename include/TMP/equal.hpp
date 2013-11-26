#ifndef TMP_EQUAL_HPP
#define TMP_EQUAL_HPP
namespace tmp
{
	template < typename T1 , typename T2 >
	struct equal ;
}
#include"TMP/all.hpp"
#include"TMP/and.hpp"
#include"TMP/at.hpp"
#include"TMP/dict.hpp"
#include"TMP/elem.hpp"
#include"TMP/eval.hpp"
#include"TMP/foldl.hpp"
#include"TMP/integral.hpp"
#include"TMP/list.hpp"
#include"TMP/set.hpp"
#include"TMP/size.hpp"
#include"TMP/zip.hpp"
namespace tmp
{
	template < typename T >
	struct equal < T , T >
		: integral < bool , true >
	{
	} ;
	template < typename T1 , typename T2 >
	struct equal
		: integral < bool , false >
	{
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
	template < typename ... T1 >
	struct equal < set < T1 ... > , set < T1 ... > >
		: integral < bool , true >
	{
	} ;
	template < typename ... T1 , typename ... T2 >
	struct equal < set < T1 ... > , set < T2 ... > >
		: and_
		<
			typename foldl
			<
				and_
				<
					arg < 0 > ,
					elem < arg < 1 > , list < T2 ... > >
				> ,
				integral < bool , true > ,
				list < T1 ... >
			>::type ,
			typename foldl
			<
				and_
				<
					arg < 0 > ,
					elem < arg < 1 > , list < T1 ... > >
				> ,
				integral < bool , true > ,
				list < T2 ... >
			>::type
		>
	{
	} ;
	template < typename ... T1 >
	struct equal < dict < T1 ... > , dict < T1 ... > >
		: integral < bool , true >
	{
	} ;
	template < typename ... T1 , typename ... T2 >
	struct equal < dict < T1 ... > , dict < T2 ... > >
		: equal < set < T1 ... > , set < T2 ... > >
	{
	} ;
}
#endif