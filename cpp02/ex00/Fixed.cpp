/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:39:51 by harndt            #+#    #+#             */
/*   Updated: 2023/05/09 11:40:02 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// =============================================================================
// CONSTRUCTOR & DESTRUCTOR
// =============================================================================

/**
 * @brief Construct a new Fixed:: Fixed object
 * 
 */
Fixed::Fixed(void) : _raw(0)
{
	LOG("Default constructor called");
	return ;
}

/**
 * @brief Construct a new Fixed:: Fixed object
 * 
 * @param src The fixed object to be copied.
 */
Fixed::Fixed(Fixed const &src)
{
	LOG("Copy constructor called");
	*this = src;
	return ;
}

/**
 * @brief Destroy the Fixed:: Fixed object
 * 
 */
Fixed::~Fixed(void)
{
	LOG("Destructor called");
	return ;
}

// =============================================================================
// OPERATOR
// =============================================================================

/**
 * @brief Overload for the '=' operator.
 * 
 * @param rhs The right hand side varible to be assigned.
 * @return Fixed& A pointer to the assigned Fixed object.
 */
Fixed & Fixed::operator= (Fixed const &rhs)
{
	LOG("Copy assignment operator called")
	if (this != &rhs)
		_raw = rhs.getRawBits();
	return *this;
}

// =============================================================================
// GETTERS
// =============================================================================

/**
 * @brief Gets the value in _raw
 * 
 * @return int _raw
 */
int	Fixed::getRawBits(void) const
{
	LOG("getRawBits member function called")
	return (this->_raw);
}

// =============================================================================
// SETTERS
// =============================================================================

/**
 * @brief Sets a new value to _raw
 * 
 * @param raw The new value to _raw.
 */
void	Fixed::setRawBits(int const raw)
{
	this->_raw = raw;
	return ;
}