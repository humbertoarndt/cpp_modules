/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:23:01 by harndt            #+#    #+#             */
/*   Updated: 2023/07/03 18:21:41 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#define SHOW_MSG true

// =============================================================================
// Constructors and Destructor
// =============================================================================

/**
 * @brief Construct a new Converter:: Converter object
 * 
 */
ScalarConverter::ScalarConverter(void)
{
	if (SHOW_MSG == true)
		LOG("🔄 Default constructor called.");
	return ;
}

/**
 * @brief Construct a new Scalar Converter:: Scalar Converter object
 * 
 * @param src The ScalarConverter object to copy.
 */
ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	if (SHOW_MSG == true)
		LOG("🔄 Copy constructor called.");
	(void)src;
	return ;
}

/**
 * @brief Destroy the Converter:: Converter object
 * 
 */
ScalarConverter::~ScalarConverter(void)
{
	if (SHOW_MSG == true)
		LOG("🔄 Destructor called.");
	return ;
}

// =============================================================================
// Operator Overload
// =============================================================================

/**
 * @brief Overload for the '=' operator
 * 
 * @param rhs The right hand side varible to be assigned.
 * @return ScalarConverter& A pointer to the assigned ScalarConverter object.
 */
ScalarConverter & ScalarConverter::operator = (ScalarConverter const &rhs)
{
	if (SHOW_MSG == true)
		LOG("🔄 Assignment operator called.");
	(void)rhs;
	return (*this);
}

// =============================================================================
// Member Function
// =============================================================================

/**
 * @brief Reads a String to check if it contains special literals for infinity.
 * 
 * @param str The string to be checked.
 * @return int 2 = Float, 3 = Double, 4 = Invalid.
 */
int		ScalarConverter::is_infinity(const std::string &str)
{
	if (!str.compare("-inff") || !str.compare("+inff") || !str.compare("nanf"))
		return (FLOAT);
	if (!str.compare("-inf") || !str.compare("+inf") || !str.compare("nan"))
		return (DOUBLE);
	return (INVALID);
}

/**
 * @brief Reads a String to check if all characters are digits.
 * 
 * @param str The string to be checked.
 * @param type 1 = Look for 'int', 2 = Look for 'float'.
 * @return true The string contains digits only.
 * @return false The string contains other character besides digits.
 */
bool	ScalarConverter::is_all_digits(const std::string &str, int type)
{
	unsigned int	i = 0;

	if (str[0] == '+' || str[0] == '-')
		i++;
	if (type == 1)
	{
		while (i < str.length())
		{
			if (!isdigit(str[i++]))
				return (false);
		}
	}
	else if (type == 2)
	{
		while (i < str.length())
		{
			if (!isdigit(str[i]) && str[i] != '.' && str[i] != 'f')
				return (false);
			i++;
		}
	}
	else
		return (false);
	return (true);
}

/**
 * @brief Checks if the given String is a char with one position, is printable
 * and not contain a digit.
 * 
 * @param str The String to be checked.
 * @return true Is a 'char'.
 * @return false Is not a 'char'.
 */
bool	ScalarConverter::is_char(const std::string &str)
{
	if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		return (true);
	return (false);
}

/**
 * @brief Checks if the given String is an 'int' containing only digits.
 * 
 * @param str The string to be checked.
 * @return true Is an 'int'.
 * @return false Is not an 'int'.
 */
bool	ScalarConverter::is_int(const std::string &str)
{
	if (is_all_digits(str, 1) && str.length() < 16)
		return (true);
	return (false);
}

/**
 * @brief Checks if the given String is a 'float'.
 * 
 * @param str The string to be checked.
 * @return true Is a 'float'.
 * @return false Is not a 'float'.
 */
bool	ScalarConverter::is_float(const std::string &str)
{
	if (str.find('f') == std::string::npos)
		return (false);
	if (is_infinity(str) == FLOAT)
		return (true);
	if (is_all_digits(str, 2) && str.find('.') <= 16)
		return (true);
	return (false);
}

/**
 * @brief Checks if the given String is a 'double'.
 * 
 * @param str The string to be checked.
 * @return true Is a 'double'.
 * @return false Is not a 'double'.
 */
bool	ScalarConverter::is_double(const std::string &str)
{
	if (is_infinity(str) == DOUBLE)
		return (true);
	if (is_all_digits(str, 2) && str.find('.') <= 16)
		return (true);
	return (false);
}

/**
 * @brief Checks the type from the given String.
 * 
 * @param input A String to check the type.
 * @return int 0 = Char, 1 = Int, 2 = Float, 3 = Double, 4 = Invalid.
 */
int	ScalarConverter::get_type(const std::string str)
{
	if (str.empty())
		return (INVALID);
	if (is_char(str))
		return (CHAR);
	if (is_int(str))
		return (INT);
	if (is_float(str))
		return (FLOAT);
	if (is_double(str))
		return (DOUBLE);
	return (INVALID);
}

void	ScalarConverter::convert(const std::string str)
{
	int	type = get_type(str);
	LOG(type);
}