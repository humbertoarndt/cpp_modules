/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:14:07 by harndt            #+#    #+#             */
/*   Updated: 2023/07/15 12:39:05 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

/**
 * @brief Looks for a needle in integer in an assumed container of integers.
 * 
 * @param haystack An assumed container of intergers.
 * @param needle an integer.
 * @return T::iterator The first occurence of needle in the haystack, in case
 * needle is not found an exception is trown.
 */
template<typename T>
typename T::iterator	easyfind(T &haystack, int needle)
{
	typename T::iterator	it;
	
	it = std::find(haystack.begin(), haystack.end(), needle);
	if (it == haystack.end())
		throw (std::out_of_range("Int not found in this container."));
	return (it);
}