#ifndef TMP_MAP_HPP
#define TMP_MAP_HPP
namespace tmp
{
	template < typename func , typename seq >
	struct map ;
}
#include"TMP/lambda.hpp"
#include"TMP/list.hpp"
#include"TMP/to_set.hpp"
#include"TMP/set.hpp"
namespace tmp
{
	template < typename func , typename ... seq >
	struct map < func , list < seq ... > >
		: list < typename lambda < func >::template apply < seq >::type ... >
	{
	} ;
	template < typename func , typename ... seq >
	struct map < func , set < seq ... > >
		: to_set
		<
			typename map
			<
				func ,
				list < seq ... >
			>::type
		>
	{
	} ;
}
#endif