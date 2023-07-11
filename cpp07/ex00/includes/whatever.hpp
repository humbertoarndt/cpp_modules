/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:47:19 by harndt            #+#    #+#             */
/*   Updated: 2023/07/11 11:50:27 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// =============================================================================
// Includes
// =============================================================================

#include <iostream>

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
