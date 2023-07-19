/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:13:18 by harndt            #+#    #+#             */
/*   Updated: 2023/07/19 17:33:01 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define SHOW_MSG true

// =============================================================================
// Exceptions
// =============================================================================

/**
 * @brief Throws an exception when the '_range' is full.
 * 
 * @return const char* Exception message.
 */
const char	*Span::RangeFullException::what(void) const throw()
{
	return ("Range is full");
}

/**
 * @brief Throws an exception when no span is found.
 * 
 * @return const char* Exception message.
 */
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

/**
 * @brief Overload for the '=' operator
 * 
 * @param rhs The right hand side varible to be assigned.
 * @return Span& A pointer to the assigned Span object.
 */
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

/**
 * @brief Overload for the 'std::ostream <<' operator.
 * 
 * @param o Output stream
 * @param span Input stream
 * @return std::ostream& Referene to the output
 */
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
// Getter/Setter
// =============================================================================

/**
 * @brief Gets the '_range' value.
 * 
 * @return intv const& '_range'
 */
intv const	&Span::getRange(void) const
{
	return (this->_range);
}

// =============================================================================
// Member Functions
// =============================================================================

/**
 * @brief Adds a single number to the Span. Any attempt to add a new element if
 * there are already N elements stored should throw an exception.
 * 
 * @param n The new element to add.
 */
void	Span::addNumber(int n)
{
	if (this->_range.size() == this->N)
		throw (Span::RangeFullException());
	this->_range.push_back(n);
	return ;
}

/**
 * @brief Adds a sequence of elements to the Span. Any attempt to add a new 
 * element if there are already N elements stored should throw an exception.
 * 
 * @param begin The new element to add.
 * @param end The new element to add.
 */
void	Span::addNumber(intv::iterator begin, intv::iterator end)
{
	while (begin != end)
	{
		if (this->_range.size() == this->N)
			throw (Span::RangeFullException());
		this->_range.push_back(*begin);
		begin++;
	}
}

/**
 * @brief Find the longest span (or distance) between all numbers stored.
 * If there are no numbers stored, or only one, no span cab be found and an
 * exception is thrown.
 * 
 * @return unsigned int The longest span.
 */
unsigned int	Span::longestSpan(void)
{
	if (this->_range.size() < 2)
		throw Span::NoSpanFoundException();

	intv	sorted(this->_range);
	std::sort(sorted.begin(), sorted.end());
	return (sorted.back() - sorted.front());
}

/**
 * @brief Find the shortes span (or distance) between all numbers stored.
 * If there are no numbers stored, or only one, no span cab be found and an
 * exception is thrown.
 * 
 * @return unsigned int The longest span.
 */
unsigned int	Span::shortestSpan(void)
{	
	if (this->_range.size() < 2)
		throw Span::NoSpanFoundException();

	intv	sorted(this->_range);
	std::sort(sorted.begin(), sorted.end());
	int	previous = sorted.front();
	intv::iterator	it = sorted.begin();
	it++;
	int	span = *it - previous;
	for (; it != sorted.end(); it++)
	{
		if (*it - previous < span)
			span = *it - previous;
		previous = *it;
	}
	return (span);
}