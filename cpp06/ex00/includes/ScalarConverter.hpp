/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:22:03 by harndt            #+#    #+#             */
/*   Updated: 2023/07/03 18:13:50 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// =============================================================================
// Includes
// =============================================================================

#include <cstdlib>
#include <iostream>

// =============================================================================
// Macros
// =============================================================================

#define LOG(x) std::cout << x << std::endl;
#define ERROR(x) std::cerr << x << std::endl;

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

		static int	get_type(const std::string str);
		static bool	is_char(const std::string &str);
		static bool	is_int(const std::string &str);
		static bool	is_float(const std::string &str);
		static bool	is_double(const std::string &str);
		static bool	is_all_digits(const std::string &str, int type);
		static int	is_infinity(const std::string &str);

	public:
		static void	convert(const std::string str);
};