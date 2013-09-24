#ifndef TMP_LAMBDA_HPP
#define TMP_LAMBDA_HPP
namespace tmp
{
	template < typename func >
	struct lambda ;
	template < unsigned int index >
	struct arg ;
}
#include"TMP/at.hpp"
#include"TMP/cons.hpp"
#include"TMP/head.hpp"
#include"TMP/id.hpp"
#include"TMP/list.hpp"
#include"TMP/tail.hpp"
namespace tmp
{
	template < unsigned int index >
	struct arg
	{
		using type = arg ;
	} ;
	namespace detail
	{
		template < typename T , unsigned int N >
		struct at
			: tmp::at < T , tmp::integral < unsigned int , N > >
		{
		} ;
		template < typename func , typename args >
		struct apply ;
		template < typename Ts , typename args >
		struct apply_helper ;
		template < typename func , typename list_ >
		struct apply_impl ;
		template < template < typename ... T_ > class func_template , typename ... T , typename ... args >
		struct apply_impl < func_template < T ... > , tmp::list < args ... > >
		{
			using type = func_template < args ... > ;
		} ;
		template < unsigned int N , typename ... Ts , typename args >
		struct apply_helper < tmp::list < tmp::arg < N > , Ts ... > , args >
			: cons
			<
				typename at < args , N >::type ,
				typename apply_helper < tmp::list < Ts ... > , args >::type
			>
		{
		} ;
		template < typename T , typename args >
		struct apply_helper
			: tmp::cons
			<
				typename apply < typename head < T >::type , args >::type ,
				typename apply_helper < typename tail < T >::type , args >::type
			>
		{
		} ;
		template < typename args >
		struct apply_helper < tmp::list < > , args >
		{
			using type = tmp::list < > ;
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
					tmp::list < T ... > ,
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