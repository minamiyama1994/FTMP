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
	namespace detail
	{
		template < typename ... T >
		struct variadic_func
		{
			using type = list < T ... > ;
		} ;
		template < typename T0 , typename T1 , typename T2 , typename T3 , typename T4 , typename T5 >
		struct func
		{
			using type = list < T0 , T1 , T2 , T3 , T4 , T5 > ;
		} ;
		static_assert
		(
			std::is_same
			<
				variadic_func < char , short , int , long , float , double >::type ,
				lambda < variadic_func < char , arg < 0 > , int , long , arg < 1 > , double > >::apply
				<
					short ,
					float
				>::type
			>::type::value ,
			"test of \"lambda\" failed."
		) ;
		static_assert
		(
			std::is_same
			<
				variadic_func < char , short , int , long , float , double , list < short , float > >::type ,
				lambda < variadic_func < char , arg < 0 > , int , long , arg < 1 > , double , list < arg < 0 > , arg < 1 > > > >::apply
				<
					short ,
					float
				>::type
			>::type::value ,
			"test of \"lambda\" failed."
		) ;
		static_assert
		(
			std::is_same
			<
				variadic_func < char , short , int , long , float , double >::type ,
				lambda < variadic_func < char , short , int , long , float , double > >::apply < >::type
			>::type::value ,
			"test of \"lambda\" failed."
		) ;
		static_assert
		(
			std::is_same
			<
				func < char , short , int , long , float , double >::type ,
				lambda < func < char , arg < 0 > , int , long , arg < 1 > , double > >::apply
				<
					short ,
					float
				>::type
			>::type::value ,
			"test of \"lambda\" failed."
		) ;
		static_assert
		(
			std::is_same
			<
				variadic_func < char , short , int , long , float , double >::type ,
				lambda < variadic_func < arg < 0 > , arg < 1 > , arg < 2 > , arg < 3 > , arg < 4 > , arg < 5 > > >::apply
				<
					char , short , int , long , float , double
				>::type
			>::type::value ,
			"test of \"lambda\" failed."
		) ;
		static_assert
		(
			std::is_same
			<
				variadic_func < >::type ,
				lambda < variadic_func < > >::apply < >::type
			>::type::value ,
			"test of \"lambda\" failed."
		) ;
	} ;
}
#endif