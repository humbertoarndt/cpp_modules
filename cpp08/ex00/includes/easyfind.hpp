/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:38:53 by harndt            #+#    #+#             */
/*   Updated: 2023/07/15 12:40:51 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* What is STL?

The Standard Template Library (STL) is a set of C++ template classes to provide 
common programming data structures and functions such as lists, stacks, arrays, 
etc. It is a library of container classes, algorithms, and iterators. It is a 
generalized library and so, its components are parameterized. Working knowledge 
of template classes is a prerequisite for working with STL.

The C++ Standard Template Library (STL) is a collection of algorithms, data 
structures, and other components that can be used to simplify the development 
of C++ programs. The STL provides a range of containers, such as vectors, lists, 
and maps, as well as algorithms for searching, sorting and manipulating data.

One of the key benefits of the STL is that it provides a way to write generic, 
reusable code that can be applied to different data types. This means that you 
can write an algorithm once, and then use it with different types of data 
without having to write separate code for each type.

The STL also provides a way to write efficient code. Many of the algorithms 
and data structures in the STL are implemented using optimized algorithms, 
which can result in faster execution times compared to custom code.

https://www.geeksforgeeks.org/the-c-standard-template-library-stl/
*/

// =============================================================================
// Includes
// =============================================================================

#include <algorithm>	//std::find
#include <iomanip>		//std::setw, std::setfill
#include <iostream>		//std::cout, std::cerr, .begin(), .end()
#include <stdexcept>	//std::out_of_range
#include <deque>		//std::deque<type>
#include <list>			//std::list<type>
#include <vector>		//std::vector<type>

// =============================================================================
// Macros
// =============================================================================

#define LOG(x) std::cout << x << EOC << std::endl;
#define ERROR(x) std::cerr << x << EOC << std::endl;
#define GRAY	"\033[0;37m"
#define YELLOW	"\033[0;33m"
#define EOC		"\033[0m"

// =============================================================================
// Functions
// =============================================================================

template<typename T>
typename T::iterator	easyfind(T &haystack, int needle);

#include "easyfind.tpp"