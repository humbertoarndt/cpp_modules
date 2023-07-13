/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:36:51 by harndt            #+#    #+#             */
/*   Updated: 2023/07/13 17:00:52 by harndt           ###   ########.fr       */
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

#include <iostream>	//std::cout, std::endl, std::cerr
#include <iomanip>	//std::setw, std::setfill
#include <cstdlib>	//sts::srand

// =============================================================================
// Macros
// =============================================================================

#define LOG(x) std::cout << x << std::endl;
#define ERROR(x) std::cerr << x << std::endl;

// =============================================================================
// Class
// =============================================================================

template<typename T>
class Array
{
	private:
		unsigned int	_n;
		T				*_ptr;

	public:
		/* Orthodox Canonical Form Methods */
		Array<T>(void);
		Array<T>(unsigned int n);
		Array<T>(Array<T> const &src);
		~Array<T>(void);

		/* Operator Overload */
		Array<T> &operator = (Array<T> const &rhs);
		T &operator [] (unsigned int index) const;

		/* Member Functions */
		unsigned int	size(void) const;
	
		/* Throw Exceptions */
		class OutOfBoundException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
};

template<typename T>
std::ostream & operator << (std::ostream &o, Array<T> const &array);

#include "Array.tpp"
