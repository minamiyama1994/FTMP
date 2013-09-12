#ifndef TMP_LAMBDA_HPP
#define TMP_LAMBDA_HPP
#include<type_traits>
#include"TMP/id.hpp"
#include"TMP/list.hpp"
namespace tmp
{
	template < unsigned int index >
	struct arg
	{
		using type = arg ;
	} ;
	namespace detail
	{
		template < typename seq , unsigned int N >
		struct at ;
		template < typename T0 , typename ... T , unsigned int N >
		struct at < list < T0 , T ... > , N >
			: at < list < T ... > , N - 1 >
		{
		} ;
		template < typename T0 , typename ... T >
		struct at < list < T0 , T ... > , 0 >
		{
			using type = T0 ;
		} ;
		template < typename head , typename tail >
		struct cons ;
		template < typename head , typename ... tail >
		struct cons < head , list < tail ... > >
			: list < head , tail ... >
		{
		} ;
		template < typename func , typename args >
		struct apply ;
		template < typename Ts , typename args >
		struct apply_helper ;
		template < typename func , typename list_ >
		struct apply_impl ;
		template < template < typename ... T_ > class func_template , typename ... T , typename ... args >
		struct apply_impl < func_template < T ... > , list < args ... > >
		{
			using type = func_template < args ... > ;
		} ;
		template < unsigned int N , typename ... Ts , typename args >
		struct apply_helper < list < tmp::arg < N > , Ts ... > , args >
			: cons
			<
				typename at < args , N >::type ,
				typename apply_helper < list < Ts ... > , args >::type
			>
		{
		} ;
		template < typename T0 , typename ... Ts , typename args >
		struct apply_helper < list < T0 , Ts ... > , args >
			: cons
			<
				typename apply < T0 , args >::type ,
				typename apply_helper < list < Ts ... > , args >::type
			>
		{
		} ;
		template < typename args >
		struct apply_helper < list < > , args >
			: list < >
		{
		} ;
		template < typename T , typename args >
		struct apply
			: tmp::id < T >
		{
		} ;
		template < template < typename ... T_ > class func_template , typename ... T , typename args >
		struct apply < func_template < T ... > , args >
			: apply_impl
			<
				func_template < T ... > ,
				typename apply_helper
				<
					list < T ... > ,
					args
				>::type
			>
		{
		} ;
	}
	template < typename func >
	struct lambda
	{
		template < typename ... T >
		struct apply
			: tmp::detail::apply
			<
				func ,
				list < T ... > 
			>::type
		{
		} ;
	} ;
}
#endif