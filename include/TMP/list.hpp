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
#include"TMP/size.hpp"
#include"TMP/zip.hpp"
namespace tmp
{
	namespace detail
	{
		template < typename T1 , typename T2 >
		struct eval_equal
			: tmp::equal < typename T1::type , typename T2::type >
		{
		} ;
	}
	template < typename ... T >
	struct list
	{
		using type = list ;
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
			all
			<
				tmp::detail::eval_equal
				<
					at < arg < 0 > , integral < int , 0 > > ,
					at < arg < 0 > , integral < int , 1 > >
				> ,
				typename zip < list < T1 ... > , list < T2 ... > >::type
			>
		>
	{
	} ;
}
#endif