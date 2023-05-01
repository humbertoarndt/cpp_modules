/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:51:39 by harndt            #+#    #+#             */
/*   Updated: 2023/05/01 15:03:25 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_H__
#define __POINT_H__

#include "Fixed.hpp"

class	Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;
		
		Point(Fixed const x, Fixed const y);

	public:
		Point(void);
		Point(float const x, float const y);
		Point(Point const &src);
		~Point(void);

		Point	&operator = (Point const &rhs);

		float	x(void) const;
		float	y(void) const;
		Fixed const	getX(void) const;
		Fixed const	getY(void) const;

		/* Arithmetic operators */
		Point	operator - (Point const &rhs) const;

		/* Vector arithmetic */
		Fixed	crossProduct(Point const &p);
};

std::ostream & operator << (std::ostream &o, Point const &p);
bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
