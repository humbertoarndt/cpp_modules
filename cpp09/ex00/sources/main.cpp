/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:13:01 by harndt            #+#    #+#             */
/*   Updated: 2023/07/24 13:22:38 by harndt           ###   ########.fr       */
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

std::fstream	*openFile(char *filename)
{
	std::string	path = filename;
	std::fstream	*fs = new std::fstream();
	fs->open(filename, std::fstream::in);
	if (fs->fail())
	{
		delete fs;
	}
	return (fs);
}

int	main(int argc, char **argv)
{
	if (!checkArgs(argc))
		return (1);
	std::fstream	*fs = openFile(argv[1]);
	std::cout << fs << std::endl;
	
	BitcoinExchange::readData();
	BitcoinExchange::printMap();
	return (0);
}