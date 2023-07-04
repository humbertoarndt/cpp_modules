/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:23:01 by harndt            #+#    #+#             */
/*   Updated: 2023/07/04 16:50:08 by harndt           ###   ########.fr       */
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
	if (str.find('f') == std::string::npos)
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
	LOG("> char:\t\t" << str[0]);
	LOG("> int:\t\t" << static_cast<int>(str[0]));
	LOG(std::fixed << std::setprecision(1) << "> float:\t" << static_cast<float>(str[0]) << "f");
	LOG(std::fixed << std::setprecision(1) << "> double:\t" << static_cast<double>(str[0]));
}

// =============================================================================
// Int conversion
// =============================================================================

/**
 * @brief Converts a integer into char.
 * 
 * @param nb The integer to convert.
 */
void	ScalarConverter::int_to_char(int nb)
{
	if (nb < LimitsChar::min() || nb > LimitsChar::max())
	{
		LOG("> char:\t\timpossible");
	}
	else if (std::isprint(nb))
	{
		LOG("> char:\t\t" << static_cast<char>(nb));
	}
	else
	{
		LOG("> char:\t\tNon displayable");
	}
}

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
	LOG("> char:\t\timpossible");
	LOG("> int:\t\timpossible");
	LOG(std::fixed << std::setprecision(1) << "> float:\t" << static_cast<float>(of) << "f");
	LOG(std::fixed << std::setprecision(1) << "> double:\t" << static_cast<double>(of));
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
	
	int_to_char(nb);
	LOG("> int:\t\t" << nb);
	LOG(std::fixed << std::setprecision(1) << "> float:\t" << static_cast<float>(nb) << "f");
	LOG(std::fixed << std::setprecision(1) << "> double:\t" << static_cast<double>(nb));
}

// =============================================================================
// Float conversion
// =============================================================================

/**
 * @brief Converts float to char;
 * 
 * @param nb The float to be converted.
 */
void	ScalarConverter::float_to_char(float nb)
{
	if (nb < LimitsChar::min() || nb > LimitsChar::max() || std::isnan(nb) || std::isinf(nb))
	{
		LOG("> char:\t\timpossible");
	}
	else if (std::isprint(nb))
	{
		LOG("> char:\t\t" << static_cast<char>(nb));
	}
	else
	{
		LOG("> char:\t\tNon displayable");
	}
}

/**
 * @brief Converts float to int;
 * 
 * @param nb The float to be converted.
 */
void	ScalarConverter::float_to_int(float nb)
{
	if (nb < LimitsInt::min() || nb > LimitsInt::max() || std::isnan(nb) || std::isinf(nb))
	{
		LOG("> int:\t\timpossible");
	}
	else
	{
		LOG("> int:\t\t" << static_cast<int>(nb));
	}
}

/**
 * @brief Converts the user's input into float.
 * 
 * @param str The user's input.
 */
void	ScalarConverter::convert_to_float(const std::string &str)
{
	float	nb = std::strtof(str.c_str(), NULL);

	float_to_char(nb);
	float_to_int(nb);
	LOG(std::fixed << std::setprecision(1) << "> float:\t" << nb << "f");
	LOG(std::fixed << std::setprecision(1) << "> double:\t" << static_cast<double>(nb));
}

// =============================================================================
// Double conversion
// =============================================================================

/**
 * @brief Converts double to char;
 * 
 * @param nb The double to be converted.
 */
void	ScalarConverter::double_to_char(double nb)
{
	if (nb < LimitsChar::min() || nb > LimitsChar::max() || std::isnan(nb) || std::isinf(nb))
	{
		LOG("> char:\t\timpossible");
	}
	else if (std::isprint(nb))
	{
		LOG("> char:\t\t" << static_cast<char>(nb));
	}
	else
	{
		LOG("> char:\t\tNon displayable");
	}
}

/**
 * @brief Converts double to int;
 * 
 * @param nb The double to be converted.
 */
void	ScalarConverter::double_to_int(double nb)
{
	if (nb < LimitsInt::min() || nb > LimitsInt::max() || std::isnan(nb) || std::isinf(nb))
	{
		LOG("> int:\t\timpossible");
	}
	else
	{
		LOG("> int:\t\t" << static_cast<int>(nb));
	}
}

/**
 * @brief Converts the user's input into double.
 * 
 * @param str The user's input.
 */
void	ScalarConverter::convert_to_double(const std::string &str)
{
	double	nb = std::strtod(str.c_str(), NULL);

	double_to_char(nb);
	double_to_int(nb);
	LOG(std::fixed << std::setprecision(1) << "> float:\t" << static_cast<float>(nb) << "f");
	LOG(std::fixed << std::setprecision(1) << "> double:\t" << nb);
}

/**
 * @brief Prints a message to when an input can't be conveted.
 * 
 */
void	ScalarConverter::invalid_conversion(void)
{
	LOG("> char:\t\timpossible");
	LOG("> int:\t\timpossible");
	LOG("> float:\timpossible");
	LOG("> double:\timpossible");
}

// =============================================================================
// Print functions
// =============================================================================

void	ScalarConverter::print_char(char c)
{
	if (std::isprint(c))
	{
		LOG("char: '" << c << "'");
	}
	else
		LOG("char: Non displayable");
}
// void	ScalarConverter::print_int(int d);
// void	ScalarConverter::print_float(float f);
// void	ScalarConverter::print_double(double d);
// // void	ScalarConverter::print_impossible(char c);


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
			invalid_conversion();
	}
}