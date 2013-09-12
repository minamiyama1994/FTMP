#ifndef TMP_AND_HPP
#define TMP_AND_HPP
namespace tmp
{
	template < typename T1 , typename T1 >
	struct or_
		: bool_ < T1::type::value && T2::type::value >
	{
	} ;
}
#endif