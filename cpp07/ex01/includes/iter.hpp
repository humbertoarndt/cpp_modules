/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:26:15 by harndt            #+#    #+#             */
/*   Updated: 2023/07/13 17:01:14 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/*What is a Template?

A template is a simple yet very powerful tool in C++. The simple idea is to pass
the data type as a parameter so that we don’t need to write the same code for 
different data types. For example, a software company may need to sort() for 
different data types. Rather than writing and maintaining multiple codes, we 
can write one sort() and pass the datatype as a parameter.

https://www.geeksforgeeks.org/templates-cpp/
https://www.codeproject.com/Articles/257589/An-Idiots-Guide-to-Cplusplus-Templates-Part-1
https://www.youtube.com/watch?v=I-hZkUa9mIs&t=456s&pp=ygUMYysrIHRlbXBsYXRl
*/

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
