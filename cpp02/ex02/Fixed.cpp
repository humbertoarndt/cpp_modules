/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:39:51 by harndt            #+#    #+#             */
/*   Updated: 2023/04/26 14:39:03 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#define SHOW_MSG false

// =============================================================================
// CONSTRUCTOR & DESTRUCTOR
// =============================================================================

Fixed::Fixed(void) : _raw(0)
{
	if (SHOW_MSG == true)
		LOG("Default constructor called");
	return ;
}

Fixed::Fixed(const int value) : _raw(value << _fractionBits)
{
	if (SHOW_MSG == true)
		LOG("Int constructor called");
	return ;
}

// Since 'value' is float can't bitshift it directly, so 'roundf' must be used.
Fixed::Fixed(const float value) : _raw(roundf(value * (1 << _fractionBits)))
{
	if (SHOW_MSG == true)
		LOG("Float constructor called");
	return ;
}

Fixed::Fixed(Fixed const &src)
{
	if (SHOW_MSG == true)
		LOG("Copy constructor called");
	*this = src;
	return ;
}

Fixed::~Fixed(void)
{
	if (SHOW_MSG == true)
		LOG("Destructor called");
	return ;
}

// =============================================================================
// OPERATORS
// =============================================================================

Fixed & Fixed::operator= (Fixed const &rhs)
{
	if (SHOW_MSG == true)
		LOG("Copy assignment operator called")
	if (this != &rhs)
		_raw = rhs.getRawBits();
	return *this;
}

// Logic Operators Overload
bool	Fixed::operator > (const Fixed &rhs) const
{
	return (getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator < (const Fixed &rhs) const
{
	return (getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator >= (const Fixed &rhs) const
{
	return (getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator <= (const Fixed &rhs) const
{
	return (getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator == (const Fixed &rhs) const
{
	return (getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator != (const Fixed &rhs) const
{
	return (getRawBits() != rhs.getRawBits());
}

// Arithmetic Operators Overload
Fixed	Fixed::operator + (const Fixed &rhs) const
{
	Fixed	i;
	
	i.setRawBits(getRawBits() + rhs.getRawBits());
	return (i);
}

Fixed	Fixed::operator - (const Fixed &rhs) const
{
	Fixed	i;

	i.setRawBits(getRawBits() - rhs.getRawBits());
	return (i);
}

Fixed	Fixed::operator * (const Fixed &rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator / (const Fixed &rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

// Increment/Decrement Operators Overload
Fixed	&Fixed::operator ++ (void)
{
	++this->_raw;
	return (*this);
}

Fixed	Fixed::operator ++ (int)
{
	Fixed	i = *this;
	
	this->_raw++;
	return (i);
}

Fixed	&Fixed::operator -- (void)
{
	--this->_raw;
	return (*this);
}

Fixed	Fixed::operator -- (int)
{
	Fixed	i = *this;
	
	this->_raw--;
	return (i);
}

// min/max Operators Overload
Fixed	&Fixed::min(Fixed &lhs, Fixed &rhs)
{
	return (lhs > rhs ? rhs : lhs);
}

Fixed	&Fixed::min(Fixed const &lhs, Fixed const &rhs)
{
	return (Fixed::min((Fixed &)lhs, (Fixed &)rhs));
}

Fixed	&Fixed::max(Fixed &lhs, Fixed &rhs)
{
	return (lhs < rhs ? rhs : lhs);
}

Fixed	&Fixed::max(Fixed const &lhs, Fixed const &rhs)
{
	return (Fixed::max((Fixed &)lhs, (Fixed &)rhs));
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

/**
 * @brief Converts rawBits into float.
 * 
 * @return float rawBits converted as float.
 */
float	Fixed::toFloat(void) const
{
	return ((float)getRawBits() / (1 << _fractionBits));
}

/**
 * @brief Convertes rawBits into int.
 * 
 * @return int rawBits converted as int.
 */
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
