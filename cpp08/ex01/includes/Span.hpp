/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:08:26 by harndt            #+#    #+#             */
/*   Updated: 2023/07/18 20:36:51 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// =============================================================================
// Includes
// =============================================================================

#include <iostream>	//std::cout, std::cerr, std::endl
#include <algorithm>
#include <vector>
#include <list>

// =============================================================================
// Macros
// =============================================================================

#define LOG(x) std::cout << x << std::endl;
#define ERROR(x) std::cerr << x << std::endl;
typedef std::vector<int>	intv;

// =============================================================================
// Class
// =============================================================================

class Span
{
	private:
		unsigned int	N;
		intv			_range;

	public:
		/* Orthodox Canonical Form methods */
		Span(void);
		Span(unsigned int);
		Span(Span const &src);
		~Span(void);
		Span &operator = (Span const &rhs);

		/* Member Functions */
		void				addNumber(int n);
		unsigned int		longestSpan(void);
		unsigned int		shortestSpan(void);
		intv const			&getRange(void) const;
		
		/* Exceptions */
		class RangeFullException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

		class NoSpanFoundException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
};

std::ostream &operator << (std::ostream &o, Span const &span);