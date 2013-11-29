#ifndef TMP_FOLDL_HPP
#define TMP_FOLDL_HPP
namespace tmp
{
	template < typename func , typename a , typename bs >
	struct foldl ;
}
#include"TMP/lambda.hpp"
#include"TMP/detail/first_half.hpp"
#include"TMP/detail/second_half.hpp"
namespace tmp
{
	namespace detail
	{
		template < typename func , typename a , typename bs1 , typename bs2 >
		struct foldl_helper ;
		template < typename func , typename a , typename bs1 , typename bs2 >
		struct foldl_helper
			: tmp::foldl
			<
				func ,
				typename tmp::foldl
				<
					func ,
					a ,
					bs1
				>::type ,
				bs2
			>
		{
		} ;
	}
	template < typename func , typename a >
	struct foldl < func , a , list < > >
	{
		using type = a ;
	} ;
	template < typename func , typename b , typename as >
	struct foldl
		: tmp::detail::foldl_helper
		<
			func ,
			b ,
			typename tmp::detail::first_half < as >::type ,
			typename tmp::detail::second_half < as >::type
		>
	{
	} ;
	template < typename func , typename a , typename bs >
	struct foldl < func , a , list < bs > >
		: lambda < func >::template apply
		<
			a ,
			bs
		>
	{
	} ;
}
#endif