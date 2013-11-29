#ifndef TMP_FOLDR_HPP
#define TMP_FOLDR_HPP
namespace tmp
{
	template < typename func , typename b , typename as >
	struct foldr ;
}
#include"TMP/lambda.hpp"
#include"TMP/detail/first_half.hpp"
#include"TMP/detail/second_half.hpp"
namespace tmp
{
	namespace detail
	{
		template < typename func , typename b , typename as1 , typename as2 >
		struct foldr_helper ;
		template < typename func , typename b , typename as1 , typename as2 >
		struct foldr_helper
			: tmp::foldr
			<
				func ,
				typename tmp::foldr
				<
					func ,
					b ,
					as2
				>::type ,
				as1
			>
		{
		} ;
	}
	template < typename func , typename b >
	struct foldr < func , b , list < > >
	{
		using type = b ;
	} ;
	template < typename func , typename b , typename as >
	struct foldr
		: tmp::detail::foldr_helper
		<
			func ,
			b ,
			typename tmp::detail::first_half < as >::type ,
			typename tmp::detail::second_half < as >::type
		>
	{
	} ;
	template < typename func , typename b , typename as >
	struct foldr < func , b , list < as > >
		: lambda < func >::template apply
		<
			as ,
			b
		>
	{
	} ;
}
#endif