/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:39:51 by harndt            #+#    #+#             */
/*   Updated: 2023/04/24 17:01:46 by harndt           ###   ########.fr       */
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

Fixed::Fixed(const int value) : _raw(value << _fractionBits)
{
	LOG("Int constructor called");
	return ;
}

// Since 'value' is float can't bitshift it directly, so 'roundf' must be used.
Fixed::Fixed(const float value) : _raw(roundf(value * (1 << _fractionBits)))
{
	LOG("Float constructor called");
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

// =============================================================================
// FUNCTIONS
// =============================================================================

float	Fixed::toFloat(void) const
{
	return ((float)getRawBits() / (1 << _fractionBits));
}

int	Fixed::toInt(void) const
{
	return (getRawBits() >> _fractionBits);
}

std::ostream & operator << (std::ostream & o, Fixed const & i)
{
	// Checks if 'i' is zero.
	if (i.getRawBits() & 0xFF)
		o << i.toFloat();
	else
		o << i.toInt();
	return (o);
}