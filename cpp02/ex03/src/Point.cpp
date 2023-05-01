/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:55:03 by harndt            #+#    #+#             */
/*   Updated: 2023/05/01 15:05:10 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#define SHOW_MSG false

// =============================================================================
// Constructor & Destructor
// =============================================================================

Point::Point(void) : _x(Fixed()), _y(Fixed())
{
	if (SHOW_MSG == true)
		LOG("Default constructor called");
	return ;
}

Point::Point(float const x, float const y) : _x(Fixed(x)), _y(Fixed(y))
{
	if (SHOW_MSG == true)
		LOG("Float constructor called");
	return ;
}

Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y)
{
	if (SHOW_MSG == true)
		LOG("Float constructor called");
	return ;
}

Point::Point(Point const &src) : _x(src.x()), _y(src.y())
{
	if (SHOW_MSG == true)
		LOG("Copy constructor called");
	return ;
}

Point::~Point(void)
{
	if (SHOW_MSG == true)
		LOG("Destructor called");
	return ;
}

// =============================================================================
// Operators
// =============================================================================

Point & Point::operator = (Point const &rhs)
{
	if (SHOW_MSG == true)
		LOG("Copy assignment operator called");
	if (this != &rhs)
		*this = Point(rhs);
	return (*this);
}

// =============================================================================
// Acessor
// =============================================================================

float	Point::x(void) const
{
	return (_x.toFloat());
}

float	Point::y(void) const
{
	return (_y.toFloat());
}

Fixed const	Point::getX(void) const
{
	return (_x);
}

Fixed const	Point::getY(void) const
{
	return (_y);
}

// =============================================================================
// INSTANCE METHODS
// =============================================================================

Point	Point::operator - (Point const &rhs) const
{
	// Use private Fixed type args constructor
	return (Point(getX() - rhs.getX(), getY() - rhs.getY()));
}

Fixed	Point::crossProduct(Point const &p)
{
	// (x1, y1, 0) * (x2, y2, 0) = (0 ,0, x1y2 - x2y1)
	// third element of cross product if z1 and z2 = 0
	return (getX() * p.getY() - p.getX() * getY());
}

// =============================================================================
// OSTREAM OVERRIDE
// =============================================================================

std::ostream & operator << (std::ostream &o, Point const &p)
{
	o << "(" << p.x() << ", " << p.y() << ")";
	return o;
}