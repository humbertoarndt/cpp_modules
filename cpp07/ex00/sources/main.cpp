/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:46:16 by harndt            #+#    #+#             */
/*   Updated: 2023/07/10 12:48:01 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#define LOG(x) std::cout << x << std::endl << RESET_COLOR;
#define YELLOW		"\033[0;33m"
#define RESET_COLOR	"\033[0m"

/**
 * @brief Tests as the subjec for module 07.
 * 
 */
void	testSubject(void)
{
	LOG(YELLOW << ">> Subject test");

	int	a = 2;
	int	b = 3;

	::swap(a, b);
	LOG("a = " << a << ", b = " << b);
	LOG("min(a, b) = " << ::min(a, b));
	LOG("max(a, b) = " << ::max(a, b));

	std::string	c = "chaine1";
	std::string	d = "chaine2";

	::swap(c, d);
	LOG("\nc = " << c << ", d = " << d);
	LOG("min(c, d) = " << ::min(c, d));
	LOG("max(c, d) = " << ::max(c, d));
	LOG("");

	return ;
}

/**
 * @brief Test functions swap(), min() and max() when an int is received.
 * 
 * @param x The first value.
 * @param y The second value.
 */
void	testInt(int x, int y)
{
	LOG(YELLOW << ">> Int test");

	LOG("x: " << x << ", y: " << y);
	::swap<int>(x, y);
	LOG("swaped x: " << x << ", swaped y: " << y);
	LOG("min(x, y) = " << ::min<int>(x, y));
	LOG("max(x, y) = " << ::max<int>(x, y));
	LOG("");

	return ;
}

/**
 * @brief Test functions swap(), min() and max() when a float is received.
 * 
 * @param x The first value.
 * @param y The second value.
 */
void	testFloat(float x, float y)
{
	LOG(YELLOW << ">> Float test");

	LOG("x: " << x << ", y: " << y);
	::swap<float>(x, y);
	LOG("swaped x: " << x << ", swaped y: " << y);
	LOG("min(x, y) = " << ::min<float>(x, y));
	LOG("max(x, y) = " << ::max<float>(x, y));
	LOG("");

	return ;
}

/**
 * @brief Test functions swap(), min() and max() when a double is received.
 * 
 * @param x The first value.
 * @param y The second value.
 */
void	testDouble(double x, double y)
{
	LOG(YELLOW << ">> Double test");

	LOG("x: " << x << ", y: " << y);
	::swap<double>(x, y);
	LOG("swaped x: " << x << ", swaped y: " << y);
	LOG("min(x, y) = " << ::min<double>(x, y));
	LOG("max(x, y) = " << ::max<double>(x, y));
	LOG("");

	return ;
}

/**
 * @brief Test functions swap(), min() and max() when a char is received.
 * 
 * @param x The first value.
 * @param y The second value.
 */
void	testChar(char x, char y)
{
	LOG(YELLOW << ">> Char test");

	LOG("x: " << x << ", y: " << y);
	::swap<char>(x, y);
	LOG("swaped x: " << x << ", swaped y: " << y);
	LOG("min(x, y) = " << ::min<char>(x, y));
	LOG("max(x, y) = " << ::max<char>(x, y));
	LOG("");

	return ;
}

/**
 * @brief Test functions swap(), min() and max() when a string is received.
 * 
 * @param x The first value.
 * @param y The second value.
 */
void	testString(std::string x, std::string y)
{
	LOG(YELLOW << ">> String test");

	LOG("x: " << x << ", y: " << y);
	::swap<std::string>(x, y);
	LOG("swaped x: " << x << ", swaped y: " << y);
	LOG("min(x, y) = " << ::min<std::string>(x, y));
	LOG("max(x, y) = " << ::max<std::string>(x, y));
	LOG("");

	return ;
}

int	main(void)
{
	testSubject();
	testInt(1, 2);
	testFloat(0.42f, 42.24f);
	testDouble(-1.42, 42.24);
	testChar('a', 'b');
	testString("Humberto", "Doisberto");
	return (0);
}