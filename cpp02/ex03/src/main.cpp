/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:41:47 by harndt            #+#    #+#             */
/*   Updated: 2023/05/01 15:10:29 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Point a(1, 1);
	Point b(4, 2);
	Point c(2, 7);
	Point point(2, 3);

	LOG("Point " << point << " is " << (bsp(a, b, c, point) ? "IN" : "OUT"));

	Point d(-4, -1);
	Point e(2, -1);
	Point f(-1, 4);
	Point point2(2, 3);

	LOG("Point " << point << " is " << (bsp(d, e, f, point2) ? "IN" : "OUT"));
	
	return (0);
}