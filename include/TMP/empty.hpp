#ifndef TMP_EMPTY_HPP
#define TMP_EMPTY_HPP
namespace tmp
{
	template < typename T >
	struct empty ;
}
#include"TMP/integral.hpp"
#include"TMP/list.hpp"
#include"TMP/set.hpp"
#include"TMP/set_to_list.hpp"
namespace tmp
{
	template < typename ... T >
	struct empty < list < T ... > >
		: integral < bool , false >
	{
	} ;
	template < >
	struct empty < list < > >
		: integral < bool , true >
	{
	} ;
	template < typename ... seq >
	struct empty < set < seq ... > >
		: empty
		<
			typename set_to_list < set < seq ... > >::type
		>
	{
	} ;
}
#endif