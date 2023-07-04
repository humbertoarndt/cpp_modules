/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:30:23 by harndt            #+#    #+#             */
/*   Updated: 2023/07/04 16:19:16 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// TODOS
// [x] Create static class ScalarConverter andh its Orthodox Canonical Form Methods
// [x] Crete Makefile
// [x] Understand the different casts in CPP
// [x] Casting in C++
// https://www.youtube.com/watch?v=pWZS1MtxI-A&pp=ygUIY3BwIGNhc3Q%3D
// [x] Dynamic Cast in C++
// https://www.youtube.com/watch?v=CiHfz6pTolQ&pp=ygUIY3BwIGNhc3Q%3D
// [x] Implicit Conversion in C++
// https://www.youtube.com/watch?v=Rr1NX1lH3oE&pp=ygUIY3BwIGNhc3Q%3D
// When should static_cast, dynamic_cast, const_cast, and reinterpret_cast be used?
// https://stackoverflow.com/questions/332030/when-should-static-cast-dynamic-cast-const-cast-and-reinterpret-cast-be-used

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ERROR(">USAGE: ./convert <literal>");
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}