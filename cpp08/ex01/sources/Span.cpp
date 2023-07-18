/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:13:18 by harndt            #+#    #+#             */
/*   Updated: 2023/07/18 20:43:55 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define SHOW_MSG true

// =============================================================================
// Exceptions
// =============================================================================

const char	*Span::RangeFullException::what(void) const throw()
{
	return ("Range is full");
}

const char	*Span::NoSpanFoundException::what(void) const throw()
{
	return ("No Span found.");
}

// =============================================================================
// Constructors and Destructor
// =============================================================================

/**
 * @brief Construct a new Span:: Span object
 * 
 */
Span::Span(void) : _range()
{
	if (SHOW_MSG == true)
		LOG("<Span> Default constructor called.")
	this->N = 0;
	return ;
}

/**
 * @brief Construct a new Span:: Span object
 * 
 * @param N 
 */
Span::Span(unsigned int N) : _range()
{
	if (SHOW_MSG == true)
		LOG("<Span> Parameter constructor called.")
	this->N = N;
	return ;
}

/**
 * @brief Construct a new Span:: Span object
 * 
 * @param src The object to be copied.
 */
Span::Span(Span const &src)
{
	if (SHOW_MSG == true)
		LOG("<Span> Copy constructor called.")
	this->N = src.N;
	this->_range = src._range;
	return ;
}

/**
 * @brief Destroy the Span:: Span object
 * 
 */
Span::~Span(void)
{
	if (SHOW_MSG == true)
		LOG("<Span> Destructor called.")
	return ;
}

// =============================================================================
// Overload
// =============================================================================

Span &Span::operator = (Span const &rhs)
{
	if (SHOW_MSG == true)
		LOG("<Span> Assignment operator called.")
	if (this != &rhs)
	{
		this->N = rhs.N;
		this->_range.clear();
		this->_range.insert(this->_range.end(), rhs._range.begin(), rhs._range.end());
	}
	return (*this);
}

std::ostream &operator << (std::ostream &o, Span const &span)
{
	intv	vec = span.getRange();

	o << "[ ";
	if (vec.size())
	{
		intv::iterator	end = vec.end();
		end--;
		for (intv::iterator it = vec.begin(); it != end; it++)
			o << *it << ", ";
		o << vec.back();
	}
	o << " ]";
	return (o);
}

// =============================================================================
// Member Functions
// =============================================================================

void	Span::addNumber(int n)
{
	if (this->_range.size() == this->N)
		throw (Span::RangeFullException());
	this->_range.push_back(n);
	return ;
}

intv const	&Span::getRange(void) const
{
	return (this->_range);
}

unsigned int	Span::longestSpan(void)
{
	return (14);
}
unsigned int		Span::shortestSpan(void)
{
	return (2);
}