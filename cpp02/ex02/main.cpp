/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:41:47 by harndt            #+#    #+#             */
/*   Updated: 2023/04/25 16:55:23 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	// Fixed	a;
	// Fixed	b;

	// a = 10.1f;
	// b = 10;

	// std::cout << "========== Logic Operators ==========" << std::endl;
	// std::cout << "a > b " << (a > b ? "true" : "false") << std::endl;
	// std::cout << "a < b " << (a < b ? "true" : "false") << std::endl;
	// std::cout << "a >= b " << (a >= b ? "true" : "false") << std::endl;
	// std::cout << "a <= b " << (a <= b ? "true" : "false") << std::endl;
	// std::cout << "a == b " << (a == b ? "true" : "false") << std::endl;
	// std::cout << "a != b " << (a != b ? "true" : "false") << std::endl;
	// std::cout << "=====================================" << std::endl << std::endl;

	// std::cout << "========== Arithmetic Operators ==========" << std::endl;
	// std::cout << "a + b " << (a + b) << std::endl;
	// std::cout << "b - a " << (b - a) << std::endl;
	// std::cout << "a * b " << (a * b) << std::endl;
	// std::cout << "a / b " << (a / b) << std::endl;
	// std::cout << "=====================================" << std::endl << std::endl;

	// std::cout << "========== Increment/Decrement Operators ==========" << std::endl;
	// std::cout << "a " << a << std::endl;
	// std::cout << "a++ " << (a++) << std::endl;
	// std::cout << "++a " << (++a) << std::endl;
	// std::cout << "b " << b << std::endl;
	// std::cout << "b-- " << (b--) << std::endl;
	// std::cout << "--b " << (b) << std::endl;
	// std::cout << "=====================================" << std::endl << std::endl;

	Fixed			a;
	Fixed	const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	return (0);
}