#ifndef TMP_INSERT_HPP
#define TMP_INSERT_HPP
#include"TMP/list_to_set.hpp"
namespace tmp
{
	template < typename set , typename T >
	struct insert
		: list_to_set
		<
			typename cons
			<
				T ,
				typename set_to_list
				<
					set
				>::type
			>::type
		>
	{
	} ;
}
#endif