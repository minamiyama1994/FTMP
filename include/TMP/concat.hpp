#ifndef TMP_CONCAT_HPP
#define TMP_CONCAT_HPP
#include"TMP/foldr.hpp"
namespace tmp
{
	template < typename seq1 , typename seq2 >
	struct concat
		: foldr
		<
			tmp::detail::eval_cons
			<
				typename lambda < func >::template apply < arg < 0 > > ,
				id < arg < 1 > >
			> ,
			list < > ,
			seq2 ,
			seq1
			
		>
	{
	} ;
	namespace detail
	{
		static_assert
		(
			std::is_same
			<
				variadic_func < char , short , int , long , float , double >::type ,
				typename concat
				<
					list < char , short , int > ,
					list < long , float , double >
				>::type
			>::type::value ,
			"test of \"concat\" failed."
		) ;
	}
}
#endif