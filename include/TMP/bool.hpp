#ifndef TMP_BOOL_HPP
#define TMP_BOOL_HPP
namespace tmp
{
	template < bool tf >
	struct bool_
	{
		using type = bool_ ;
		static constexpr bool value = tf ;
	} ;
}
#endif