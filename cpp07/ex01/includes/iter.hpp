/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:26:15 by harndt            #+#    #+#             */
/*   Updated: 2023/07/10 15:35:34 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// =============================================================================
// Includes
// =============================================================================

#include <iostream>
#define YELLOW		"\033[0;33m"
#define RESET_COLOR	"\033[0m"

// =============================================================================
// Functions
// =============================================================================

/**
 * @brief A function that takes 3 parameters and return nothin
 * 
 * @param array Address of an array.
 * @param size  The length of the array.
 * @param fn A function that will be call on every element of the array.
 */
template<typename T>
void	iter(T *array, int size, void(*fn)(T const &value))
{
	if (!array)
		return ;
	for (int i = 0; i < size; i++)
		fn(array[i]);
	return ;
}

/**
 * @brief Prints a value.
 * 
 * @param x The value to be printed.
 */
template<typename T>
void	print(T x)
{
	std::cout << x << std::endl;
	return ;
}
