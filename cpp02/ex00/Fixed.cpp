/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:39:51 by harndt            #+#    #+#             */
/*   Updated: 2023/04/24 14:50:39 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// =============================================================================
// CONSTRUCTOR & DESTRUCTOR
// =============================================================================

Fixed::Fixed(void) : _raw(0)
{
	LOG("Default constructor called");
	return ;
}

Fixed::Fixed(Fixed const &src)
{
	LOG("Copy constructor called");
	*this = src;
	return ;
}

Fixed::~Fixed(void)
{
	LOG("Destructor called");
	return ;
}

// =============================================================================
// OPERATOR
// =============================================================================

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

int	Fixed::getRawBits(void) const
{
	LOG("getRawBits member function called")
	return (this->_raw);
}

// =============================================================================
// SETTERS
// =============================================================================

void	Fixed::setRawBits(int const raw)
{
	this->_raw = raw;
	return ;
}