/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:36:51 by harndt            #+#    #+#             */
/*   Updated: 2023/07/12 15:20:45 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
