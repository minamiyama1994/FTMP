#ifndef TMP_EMPTY_HPP
#define TMP_EMPTY_HPP
namespace tmp
{
	template < typename T >
	struct empty ;
}
#include"TMP/dict.hpp"
#include"TMP/integral.hpp"
#include"TMP/list.hpp"
#include"TMP/set.hpp"
#include"TMP/to_list.hpp"
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
			typename to_list < set < seq ... > >::type
		>
	{
	} ;
	template < typename ... seq >
	struct empty < dict < seq ... > >
		: empty
		<
			typename to_list < dict < seq ... > >::type
		>
	{
	} ;
}
#endif