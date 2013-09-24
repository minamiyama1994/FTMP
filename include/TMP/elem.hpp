#ifndef TMP_ELEM_HPP
#define TMP_ELEM_HPP
namespace tmp
{
	template < typename T , typename seq >
	struct elem ;
}
#include"TMP/any.hpp"
#include"TMP/equal.hpp"
#include"TMP/integral.hpp"
#include"TMP/list.hpp"
#include"TMP/set.hpp"
namespace tmp
{
	template < typename T , typename seq >
	struct elem
		: any < equal < T , arg < 0 > > , seq >
	{
	} ;
	template < typename T , typename ... seq1 , typename ... seq2 >
	struct elem < T , list < seq1 ... , T , seq2 ... > >
		: integral < bool , true >
	{
	} ;
	template < typename T , typename ... seq1 , typename ... seq2 >
	struct elem < T , set < seq1 ... , T , seq2 ... > >
		: integral < bool , true >
	{
	} ;
}
#endif