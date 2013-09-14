#ifndef TMP_EVAL_IF_C_HPP
#define TMP_EVAL_IF_C_HPP
namespace tmp
{
	template < bool tf , typename T1 , typename T2 >
	struct eval_if_c ;
}
namespace tmp
{
	template < typename T1 , typename T2 >
	struct eval_if_c < true , T1 , T2 >
	{
		using type = typename T1::type ;
	} ;
	template < typename T1 , typename T2 >
	struct eval_if_c < false , T1 , T2 >
	{
		using type = typename T2::type ;
	} ;
}
#endif