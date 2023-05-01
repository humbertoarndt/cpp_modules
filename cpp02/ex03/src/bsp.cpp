/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:05:34 by harndt            #+#    #+#             */
/*   Updated: 2023/05/01 15:03:07 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
Determining if an arbitrary point lies inside a triangle defined by three points
https://math.stackexchange.com/questions/51326/determining-if-an-arbitrary-
point-lies-inside-a-triangle-defined-by-three-points

This is a fairly well known algorithm. It all comes down to using the cross
product. Define the vectors AB, BC and CA and the vectors AP, BP and CP.
Then P is inside the triangle formed by A,B and C if and only if all of the
cross products AB×AP, BC×BP and CA×CP point in the same direction relative to
the plane. That is, either all of them point out of the plane, or all of them
point into the plane.

http://totologic.blogspot.com/2014/01/accurate-point-in-triangle-test.html
https://blackpawn.com/texts/pointinpoly/
*/

bool	sameSide(Point const p1, Point const p2, Point const a, Point const b)
{
	Fixed cp1 = (b - a).crossProduct(p1 - a);
	Fixed cp2 = (b - a).crossProduct(p2 - a);

	return (cp1 * cp2 >= 0);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	return 	sameSide(point, a, b, c)
		&&	sameSide(point, b, a, c)
		&&	sameSide(point, c, a, b);
}
