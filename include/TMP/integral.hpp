#ifndef TMP_INTEGRAL_HPP
#define TMP_INTEGRAL_HPP
namespace tmp
{
	template < typename T , T val >
	struct integral ;
}
namespace tmp
{
	template < typename T , T val >
	struct integral
	{
		using type = integral ;
		static constexpr T value = val ;
	} ;
}
#endif