/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:13:01 by harndt            #+#    #+#             */
/*   Updated: 2023/07/20 13:32:09 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/**
 * @brief Checks the number of args received from command line.
 * 
 * @param argc The number of args.
 * @return true The number of args is valid.
 * @return false The number of args is invalid.
 */
bool	checkArgs(int argc)
{
	if (argc != 2)
	{
		ERROR(">USAGE: ./btc <filename>");
		return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	if (!checkArgs(argc))
		return (1);
	LOG(argv[1]);
	return (0);
}