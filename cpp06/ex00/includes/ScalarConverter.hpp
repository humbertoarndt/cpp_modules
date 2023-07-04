/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:22:03 by harndt            #+#    #+#             */
/*   Updated: 2023/07/04 16:47:50 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// =============================================================================
// Includes
// =============================================================================

#include <cmath>	// std::isnan, std::isinf
#include <cstdlib>	// std::atoi
#include <iostream>	// std::cout, std::cerr
#include <limits>	// std::numeric_limits
#include <iomanip>	// std::setprecision

// =============================================================================
// Macros
// =============================================================================

#define LOG(x) std::cout << x << std::endl;
#define ERROR(x) std::cerr << x << std::endl;
typedef std::numeric_limits<char> LimitsChar;
typedef std::numeric_limits<int> LimitsInt;
typedef std::numeric_limits<float> LimitsFloat;

// =============================================================================
// Enumeration
// =============================================================================

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID,
};

// =============================================================================
// Class
// =============================================================================

class ScalarConverter
{
	private:
		/* Orthodox Canonical Form Methods */
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter &operator = (ScalarConverter const &rhs);
		~ScalarConverter(void);

		/* Get type */
		static int	get_type(const std::string str);
		static bool	is_char(const std::string &str);
		static bool	is_int(const std::string &str);
		static bool	is_float(const std::string &str);
		static bool	is_double(const std::string &str);
		static bool	is_all_digits(const std::string &str, int type);
		static int	is_infinity(const std::string &str);

		/* Char conversion */
		static void	convert_to_char(const std::string &str);
		
		/* Int conversion */
		static void	convert_to_int(const std::string &str);
		static bool	is_overflow(const std::string &str);
		static void	int_to_char(int nb);
		
		/* Float conversion */
		static void	convert_to_float(const std::string &str);
		static void	float_to_char(float nb);
		static void	float_to_int(float nb);
		
		/* Double conversion */
		static void	convert_to_double(const std::string &str);
		static void	double_to_char(double nb);
		static void	double_to_int(double nb);

		/* Print functions */
		static void	print_char(char c);
		// static void	print_int(int d);
		// static void	print_float(float f);
		// static void	print_double(double d);
		// static void	print_impossible(char c);
		
		/* Invalid conversion */
		static void	invalid_conversion(void);

	public:
		static void	convert(const std::string str);
};