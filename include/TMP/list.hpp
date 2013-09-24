#ifndef TMP_LIST_HPP
#define TMP_LIST_HPP
namespace tmp
{
	template < typename ... T >
	struct list ;
}
namespace tmp
{
	template < typename ... T >
	struct list
	{
		using type = list ;
	} ;
}
#endif