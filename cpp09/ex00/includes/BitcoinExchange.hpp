/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:25:22 by harndt            #+#    #+#             */
/*   Updated: 2023/07/24 13:25:49 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// =============================================================================
// Includes
// =============================================================================

#include <fstream>	// std::fstream, open()
#include <iostream>	// std::cout(), std::cerr()
#include <map>		// std::map<,>
#include <sstream>	// std::istringstream
#include <stdlib.h>	// atof()
#include <string>	// c_str()

// =============================================================================
// Macros
// =============================================================================

#define LOG(x) std::cout << x << std::endl;
#define ERROR(x) std::cerr << x << std::endl;

// =============================================================================
// Class
// =============================================================================

class BitcoinExchange
{
	private:
		static std::map<std::string, double>	_map;

		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange &operator = (BitcoinExchange const &rhs);
		~BitcoinExchange(void);

	public:
		static void	readData(void);
		static void	printMap(void);
};