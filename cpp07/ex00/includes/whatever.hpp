/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:47:19 by harndt            #+#    #+#             */
/*   Updated: 2023/07/13 17:01:03 by harndt           ###   ########.fr       */
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

// =============================================================================
// Function
// =============================================================================

/**
 * @brief Swaps the values of two given arguments.
 * 
 * @param x First value.
 * @param y Second value.
 */
template<typename T>
void	swap(T &x, T &y)
{
	T	z;
	
	z = x;
	x = y;
	y = z;
}

/**
 * @brief Compares the two values passed in its arguments and returns the 
 * smallest one.
 * 
 * @param x First value.
 * @param y Second value.
 * @return T const& Returns the smallest one, or the second when both are equal.
 */
template<typename T>
T const	&min(T const &x, T const &y) {return (x < y ? x : y);}

/**
 * @brief Compares the two values passed in its arguments and returns the 
 * smallest one.
 * 
 * @param x First value.
 * @param y Second value.
 * @return T const& Returns the smallest one, or the second when both are equal.
 */
template<typename T>
T const	&max(T const &x, T const &y) {return (x > y ? x : y);}
