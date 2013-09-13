#ifndef TMP_ZIP_HPP
#define TMP_ZIP_HPP
#include"TMP/any.hpp"
#include"TMP/eval_if.hpp"
#include"TMP/empty.hpp"
namespace tmp
{
	template < typename ... T >
	struct zip
		: eval_if
		<
			any < empty < arg < 0 > > , list < typename head < T >::type ... > > ,
			list < > ,
			cons < list < typename head < T >::type ... > , list < typename tail < T >::type ... > >
		>
	{
	} ;
}
#endif