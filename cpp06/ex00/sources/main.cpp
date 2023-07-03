/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:30:23 by harndt            #+#    #+#             */
/*   Updated: 2023/07/03 11:37:53 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// TODOS
// [] Create static class ScalarConverter andh its Orthodox Canonical Form Methods
// [] Crete Makefile
// [] Understand the different casts in CPP
// [x] Casting in C++
// https://www.youtube.com/watch?v=pWZS1MtxI-A&pp=ygUIY3BwIGNhc3Q%3D
// [] Dynamic Cast in C++
// https://www.youtube.com/watch?v=CiHfz6pTolQ&pp=ygUIY3BwIGNhc3Q%3D
// [] Implicit Conversion in C++
// https://www.youtube.com/watch?v=Rr1NX1lH3oE&pp=ygUIY3BwIGNhc3Q%3D
// When should static_cast, dynamic_cast, const_cast, and reinterpret_cast be used?
// https://stackoverflow.com/questions/332030/when-should-static-cast-dynamic-cast-const-cast-and-reinterpret-cast-be-used

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ERROR("erro");
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	// double	a = 5.30;
	// double	b = (a + 2.45);
	// double	c = (int)(a) + 2.45;
	// double	d = static_cast<int>(a) + 2.45;
	// double	e = a + 2.45;

	// LOG("(int)5.30 + 2.45 = " << c);
	// LOG("static_cast<int>(a) + 2.45 = " << d);
	// LOG("a + 2.45 = " << e);

	return (0);
}