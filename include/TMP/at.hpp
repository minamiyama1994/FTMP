#ifndef TMP_AT_HPP
#define TMP_AT_HPP
namespace tmp
{
	template < typename T , typename index_type >
	struct at ;
}
#include<type_traits>
#include"TMP/head.hpp"
#include"TMP/id.hpp"
#include"TMP/integral.hpp"
#include"TMP/list.hpp"
#include"TMP/tail.hpp"
namespace tmp
{
	namespace detail
	{
		template < typename I , typename N , typename T , typename enable = void >
		struct skip ;
		template < typename index_type , index_type I , index_type N , typename ... T >
		struct skip < tmp::integral < index_type , I > , tmp::integral < index_type , N > , tmp::list < T ... > , typename std::enable_if < ( I == 0 ) >::type >
			: tmp::id < tmp::list < T ... > >
		{
		} ;
		template < typename index_type , index_type I , index_type N , typename ... T >
		struct skip < tmp::integral < index_type , I > , tmp::integral < index_type , N > , tmp::list < T ... > , typename std::enable_if < ( I != 0 && I < N / 2 ) >::type >
			: skip
			<
				tmp::integral < index_type , I - 1 > ,
				tmp::integral < index_type , N / 2 - 1 > ,
				typename tmp::tail < tmp::list < T ... > >::type
			>
		{
		} ;
		template < typename index_type , index_type I , index_type N , typename ... T >
		struct skip < tmp::integral < index_type , I > , tmp::integral < index_type , N > , tmp::list < T ... > , typename std::enable_if < ( I != 0 && I >= N / 2 ) >::type >
			: skip
			<
				tmp::integral < index_type , I - N / 2 > ,
				tmp::integral < index_type , N - N / 2 > ,
				typename skip
				<
					tmp::integral < index_type , N / 2 - 1 > ,
					tmp::integral < index_type , N / 2 > ,
					typename tmp::tail < tmp::list < T ... > >::type
				>::type
			>
		{
		} ;
	}
	template < typename ... T , typename index_type , index_type index >
	struct at < list < T ... > , integral < index_type , index > >
		: head
		<
			typename tmp::detail::skip
			<
				integral < index_type , index > ,
				integral < index_type , sizeof ... ( T ) > ,
				list < T ... >
			>::type
		>
	{
	} ;
}
#endif