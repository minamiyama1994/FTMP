#ifndef TMP_DICT_HPP
#define TMP_DICT_HPP
namespace tmp
{
	template < typename ... T >
	struct dict ;
}
namespace tmp
{
	template < typename ... T >
	struct dict
	{
		using type = dict ;
	} ;
}
#endif