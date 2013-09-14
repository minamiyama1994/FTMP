#ifndef TMP_IF_C_HPP
#define TMP_IF_C_HPP
namespace tmp
{
	template < bool tf , typename T1 , typename T2 >
	struct if_c ;
}
namespace tmp
{
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
}
#endif