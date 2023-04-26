/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:41:47 by harndt            #+#    #+#             */
/*   Updated: 2023/04/26 14:58:42 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * @brief Prints 'n' times the given char 'c'.
 * 
 * @param c The char to be printed.
 * @param n The number of times to print.
 */
void	print_n_times(char c, int n)
{
	std::cout << std::string(n, c) << std::endl;
}

 /**
  * @brief Prints header with a title.
  * 
  * @param str The header's title.
  * @param a Refernce to a Fixed value.
  * @param b Refernce to a Fixed const value.
  */
void	printHeader(std::string const str, Fixed &a, Fixed const &b)
{
	std::cout << str;
	print_n_times('=', (45 - str.length()));
	std::cout << "a: " << a << "\t";
	std::cout << "b: " << b << std::endl << std::endl;
}

/**
 * @brief Prints footer.
 * 
 */
void	printFooter(void)
{
	print_n_times('=', 45);
	std::cout << std::endl;
}

/**
 * @brief Prints the tests for min/max operators
 * 
 * @param a Reference to a Fixed value.
 * @param b Reference to a Fixed value.
 */
void	minMaxTest(Fixed &a, Fixed &b)
{
	// Reset 'a' and 'b' values.
	for (int i = 0; i < 2; i++)
	{
		a++;
		b++;
	}
	printHeader("[Min/Max Operators Tests] ", a, b);
	std::cout << "min: " << Fixed::min(a, b) << std::endl;
	std::cout << "max: " << Fixed::max(a, b) << std::endl;
	printFooter();
}

/**
 * @brief Prints the tests for unary operators
 * 
 * @param a Reference to a Fixed value.
 * @param b Reference to a Fixed value.
 */
void	unaryTest(Fixed &a, Fixed &b)
{
	printHeader("[Unary Operators Tests] ", a, b);
	std::cout << "++a " << (++a) << std::endl;
	std::cout << "a++ " << (a++) << std::endl;
	std::cout << "++b " << (++b) << std::endl;
	std::cout << "b++ " << (b++) << std::endl;
	
	a = 42.05f;
	b = 19.05f;
	
	std::cout << "--a " << (--a) << std::endl;
	std::cout << "a-- " << (a--) << std::endl;
	std::cout << "--b " << (--b) << std::endl;
	std::cout << "b-- " << (b--) << std::endl;
	printFooter();
}

/**
 * @brief Prints the tests for arithmetic operators
 * 
 * @param a Reference to a Fixed value.
 * @param b Reference to a Fixed value.
 */
void	arithmeticTest(Fixed &a, Fixed &b)
{
	printHeader("[Arithmetic Operators Tests] ", a, b);
	std::cout << "a + b = " << (a + b) << std::endl;
	std::cout << "a - b = " << (a - b) << std::endl;
	std::cout << "a * b = " << (a * b) << std::endl;
	std::cout << "a / b = " << (a / b) << std::endl;
	std::cout << "a + (5.05f/2) = " << (a + (Fixed(5.05f)/Fixed(2))) << std::endl;
	std::cout << "a - (5.05f/2) = " << (a - (Fixed(5.05f)/Fixed(2))) << std::endl;
	std::cout << "b * 2.2f = " << (b * (Fixed(2.2f))) << std::endl;
	std::cout << "b / 2.2f = " << (b / (Fixed(2.2f))) << std::endl;
	printFooter();
}

/**
 * @brief Prints the tests for logic operators
 * 
 * @param a Reference to a Fixed value.
 * @param b Reference to a Fixed value.
 */
void	logicTest(Fixed &a, Fixed &b)
{
	printHeader("[Logic Operators Tests] ", a, b);
	std::cout << "a > b = " << (a > b ? "true" : "false") << std::endl;
	std::cout << "a < b = " << (a < b ? "true" : "false") << std::endl;
	std::cout << "a >= b = " << (a >= b ? "true" : "false") << std::endl;
	std::cout << "a <= b = " << (a <= b ? "true" : "false") << std::endl;
	std::cout << "a == b = " << (a == b ? "true" : "false") << std::endl;
	std::cout << "a != b = " << (a != b ? "true" : "false") << std::endl;
	printFooter();
}

/**
 * @brief Prints the tests as the subject's example
 * 
 */
void	subjectTest(void)
{
	Fixed		a;
	Fixed const	b(Fixed (5.05f) * Fixed(2));

	printHeader("[Subject Tests] ", a, b);
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	printFooter();
}

int	main(void)
{
	Fixed	a(42.05f);
	Fixed	b(19.05f);

	subjectTest();
	logicTest(a, b);
	arithmeticTest(a, b);
	unaryTest(a, b);
	minMaxTest(a, b);

	return (0);
}