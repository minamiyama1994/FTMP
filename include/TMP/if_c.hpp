#ifndef TMP_IF_C_HPP
#define TMP_IF_C_HPP
namespace tmp
{
	template < bool tf , typename T1 , typename T2 >
	struct if_c ;
	template < typename T1 , typename T2 >
	struct if_c < true , T1 , T2 >
	{
		using type = T1 ;
	} ;
	template < typename T1 , typename T2 >
	struct if_c < false , T1 , T2 >
	{
		using type = T2 ;
	} ;
	namespace detail
	{
		static_assert
		(
			std::is_same
			<
				if_c < true , char , int >::type ,
				char
			>::type::value ,
			"test of \"if_c\" failed."
		) ;
		static_assert
		(
			std::is_same
			<
				if_c < false , char , int >::type ,
				int
			>::type::value ,
			"test of \"if_c\" failed."
		) ;
	}
}
#endif