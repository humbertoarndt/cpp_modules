/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:23:01 by harndt            #+#    #+#             */
/*   Updated: 2023/07/04 18:21:34 by harndt           ###   ########.fr       */
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
// Get type functions
// =============================================================================

/**
 * @brief Reads the user's input to check if it contains special literals for infinity.
 * 
 * @param str The user's input.
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
 * @brief Reads the user's input to check if all characters are digits.
 * 
 * @param str The user's input.
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
 * @brief Checks if the user's input is a char with one position, is printable
 * and not contain a digit.
 * 
 * @param str The Suser's input.
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
 * @brief Checks if the user's input is an 'int' containing only digits.
 * 
 * @param str The user's input.
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
 * @brief Checks if the user's input is a 'float'.
 * 
 * @param str The user's input.
 * @return true Is a 'float'.
 * @return false Is not a 'float'.
 */
bool	ScalarConverter::is_float(const std::string &str)
{
	size_t dlength = str.length() - 1;

	if (str.at(dlength) != 'f')
		return (false);
	if (is_infinity(str) == FLOAT)
		return (true);
	if (is_all_digits(str, 2) && str.find('.') <= 16)
		return (true);
	return (false);
}

/**
 * @brief Checks if the user's input is a 'double'.
 * 
 * @param str The user's input.
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
 * @brief Checks the type from the user's input.
 * 
 * @param str The user's input.
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

// =============================================================================
// Char conversion
// =============================================================================

/**
 * @brief Converts the user's input into char.
 * 
 * @param str The user's input.
 */
void	ScalarConverter::convert_to_char(const std::string &str)
{
	print_char(str[0]);
	print_int(static_cast<int>(str[0]));
	print_float(static_cast<float>(str[0]));
	print_double(static_cast<double>(str[0]));
}

// =============================================================================
// Int conversion
// =============================================================================

/**
 * @brief Checks if the number received as input doesn't overflow.
 * 
 * @param str The user's input.
 * @return true The user's input is an overflow.
 * @return false The user's input is not an overflow.
 */
bool	ScalarConverter::is_overflow(const std::string &str)
{
	long int	of = std::atol(str.c_str());
	
	if (of >= LimitsInt::min() && of <= LimitsInt::max())
		return (true);
	print_impossible("char");
	print_impossible("int");
	print_float(static_cast<float>(of));
	print_double(static_cast<double>(of));
	return (false);
}

/**
 * @brief Converts the user's input into int.
 * 
 * @param str The user's input.
 */
void	ScalarConverter::convert_to_int(const std::string &str)
{
	if (!is_overflow(str))
		return ;
	int	nb = std::atoi(str.c_str());
	
	if (nb < LimitsChar::min() || nb > LimitsChar::max())
		print_impossible("char");
	else
		print_char(static_cast<char>(nb));
	print_int(nb);
	print_float(static_cast<float>(nb));
	print_double(static_cast<double>(nb));
}

// =============================================================================
// Float conversion
// =============================================================================

/**
 * @brief Converts the user's input into float.
 * 
 * @param str The user's input.
 */
void	ScalarConverter::convert_to_float(const std::string &str)
{
	float	nb = std::strtof(str.c_str(), NULL);

	if (nb < LimitsChar::min() || nb > LimitsChar::max() || std::isnan(nb) || std::isinf(nb))
		print_impossible("char");
	else
		print_char(static_cast<char>(nb));
	
	if (nb < LimitsInt::min() || nb > LimitsInt::max() || std::isnan(nb) || std::isinf(nb))
		print_impossible("int");
	else
		print_int(static_cast<int>(nb));
	print_float(nb);
	print_double(static_cast<double>(nb));
}

// =============================================================================
// Double conversion
// =============================================================================

/**
 * @brief Converts the user's input into double.
 * 
 * @param str The user's input.
 */
void	ScalarConverter::convert_to_double(const std::string &str)
{
	double	nb = std::strtod(str.c_str(), NULL);

	if (nb < LimitsChar::min() || nb > LimitsChar::max() || std::isnan(nb) || std::isinf(nb))
		print_impossible("char");
	else
		print_char(static_cast<char>(nb));
	if (nb < LimitsInt::min() || nb > LimitsInt::max() || std::isnan(nb) || std::isinf(nb))
		print_impossible("int");
	else
		print_int(static_cast<int>(nb));
	if (nb < LimitsFloat::min() || nb > LimitsFloat::max())
		print_impossible("float");
	else
		print_float(static_cast<float>(nb));
	print_double(nb);
}

// =============================================================================
// Print functions
// =============================================================================

/**
 * @brief Prints a char.
 * 
 * @param c The char to be printed;
 */
void	ScalarConverter::print_char(char c)
{
	if (std::isprint(c))
	{
		LOG("char: '" << c << "'");
	}
	else
	{
		LOG("char: Non displayable");
	}
}

/**
 * @brief Prints an int.
 * 
 * @param d The int to be printed.
 */
void	ScalarConverter::print_int(int d)
{
	LOG("int: " << d);
}

/**
 * @brief Prints a float.
 * 
 * @param f The float to be printed.
 */
void	ScalarConverter::print_float(float f)
{
	LOG("float: " << std::fixed << std::setprecision(1) << f << "f");
}

/**
 * @brief Prints a double.
 * 
 * @param d The double to be printed.
 */
void	ScalarConverter::print_double(double d)
{
	LOG("double: " << std::fixed << std::setprecision(1) << d);
}

/**
 * @brief Prints a message when is impossible to print a conversion.
 * 
 * @param type The imposible tipe to convert.
 */
void	ScalarConverter::print_impossible(const std::string type)
{
	LOG(type << ": impossible");
}

/**
 * @brief Prints a message to when an input can't be conveted.
 * 
 */
void	ScalarConverter::impossible_conversion(void)
{
	print_impossible("char");
	print_impossible("int");
	print_impossible("float");
	print_impossible("double");
}

// =============================================================================
// Convert function
// =============================================================================

/**
 * @brief Identify the type of the user's input and converts it into char,
 * int, float and double.
 * 
 * @param str The user's input.
 */
void	ScalarConverter::convert(const std::string str)
{
	int	type = get_type(str);

	switch (type)
	{
		case CHAR:
			convert_to_char(str);
			break;
		case INT:
			convert_to_int(str);
			break;
		case FLOAT:
			convert_to_float(str);
			break;
		case DOUBLE:
			convert_to_double(str);
			break;
		default :
			impossible_conversion();
	}
}