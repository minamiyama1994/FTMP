/*
 *  Functional Template Meta Programming Library
 *  Copyright (C) 2013  Masakazu Minamiyama
 *  
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef FTMP_IF_C_HPP
#define FTMP_IF_C_HPP
namespace ftmp
{
	template < bool tf , typename T1 , typename T2 >
	struct if_c ;
}
namespace ftmp
{
	template < typename T1 , typename T2 >
	struct if_c < true , T1 , T2 >
	{
		using type = T1 ;
	} ;
	template < typename T1 , typename T2 >
	struct if_c < false , T1 , T2 >
	{
		using type = T2 ;
	} ;
}
#endif