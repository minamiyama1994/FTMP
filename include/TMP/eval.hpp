#ifndef TMP_EVAL_HPP
#define TMP_EVAL_HPP
namespace tmp
{
	template < typename T >
	struct eval ;
}
namespace tmp
{
	template < template < typename ... T_ > class F , typename ... T >
	struct eval < F < T ... > >
		: F < typename T::type ... >
	{
	} ;
}
#endif