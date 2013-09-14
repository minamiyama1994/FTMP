#ifndef TMP_ID_HPP
#define TMP_ID_HPP
namespace tmp
{
	template < typename T >
	struct id ;
}
namespace tmp
{
	template < typename T >
	struct id
	{
		using type = T ;
	} ;
}
#endif