/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:55:03 by harndt            #+#    #+#             */
/*   Updated: 2023/05/09 12:31:27 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#define SHOW_MSG false

// =============================================================================
// Constructor & Destructor
// =============================================================================

/**
 * @brief Construct a new Point:: Point object
 * 
 */
Point::Point(void) : _x(Fixed()), _y(Fixed())
{
	if (SHOW_MSG == true)
		LOG("Default constructor called");
	return ;
}

/**
 * @brief Construct a new Point:: Point object
 * 
 * @param x x coordinate value.
 * @param y y coordinate value.
 */
Point::Point(float const x, float const y) : _x(Fixed(x)), _y(Fixed(y))
{
	if (SHOW_MSG == true)
		LOG("Float constructor called");
	return ;
}

/**
 * @brief Construct a new Point:: Point object
 * 
 * @param x x coordinate value.
 * @param y y coordinate value.
 */
Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y)
{
	if (SHOW_MSG == true)
		LOG("Float constructor called");
	return ;
}

/**
 * @brief Construct a new Fixed:: Fixed object
 * 
 * @param src The fixed object to be copied.
 */
Point::Point(Point const &src) : _x(src.x()), _y(src.y())
{
	if (SHOW_MSG == true)
		LOG("Copy constructor called");
	return ;
}

/**
 * @brief Destroy the Point:: Point object
 * 
 */
Point::~Point(void)
{
	if (SHOW_MSG == true)
		LOG("Destructor called");
	return ;
}

// =============================================================================
// Operators
// =============================================================================

/**
 * @brief Overload for the '=' operator.
 * 
 * @param rhs The right hand side varible to be assigned.
 * @return Fixed& A pointer to the assigned Fixed object.
 */
Point & Point::operator = (Point const &rhs)
{
	if (SHOW_MSG == true)
		LOG("Copy assignment operator called");
	if (this != &rhs)
		*this = Point(rhs);
	return (*this);
}

/**
 * @brief Overload for the '-' operator.
 * 
 * @param rhs The right hand side variable to be subtracted from.
 * @return Point The subtract's result.
 */
Point	Point::operator - (Point const &rhs) const
{
	// Use private Fixed type args constructor
	return (Point(getX() - rhs.getX(), getY() - rhs.getY()));
}

// =============================================================================
// GETTERS
// =============================================================================

/**
 * @brief Gets the '_x' value.
 * 
 * @return float '_x' converted as float.
 */
float	Point::x(void) const
{
	return (_x.toFloat());
}

/**
 * @brief Gets the '_y' value.
 * 
 * @return float '_x' converted as float.
 */
float	Point::y(void) const
{
	return (_y.toFloat());
}

/**
 * @brief Gets the '_x' value.
 * 
 * @return Fixed const '_x'
 */
Fixed const	Point::getX(void) const
{
	return (_x);
}

/**
 * @brief Gets the '_y' value.
 * 
 * @return Fixed const '_y'
 */
Fixed const	Point::getY(void) const
{
	return (_y);
}

// =============================================================================
// INSTANCE METHODS
// =============================================================================

/**
 * @brief Calculates the cross product between two distinguished points.
 * 
 * @param p A point.
 * @return Fixed The equation's result.
 */
Fixed	Point::crossProduct(Point const &p)
{
	// (x1, y1, 0) * (x2, y2, 0) = (0 ,0, x1y2 - x2y1)
	// third element of cross product if z1 and z2 = 0
	return (getX() * p.getY() - p.getX() * getY());
}

// =============================================================================
// OSTREAM OVERLOAD
// =============================================================================

/**
 * @brief Overload for the 'std::ostream <<' operator.
 * 
 * @param o Output stream.
 * @param p Input stream.
 * @return std::ostream& Reference to the output.
 */
std::ostream & operator << (std::ostream &o, Point const &p)
{
	o << "(" << p.x() << ", " << p.y() << ")";
	return o;
}