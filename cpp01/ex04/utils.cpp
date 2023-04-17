/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:11:04 by harndt            #+#    #+#             */
/*   Updated: 2023/04/17 16:28:34 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

/**
 * @brief Checks if the number of arguments is correct.
 * 
 * @param argc The argument counter received by command line.
 * @return true When the argument counter meets the established rules.
 * @return false When the argument counter doesn't meet the established rules.
 */
bool	check_arg_nb(int argc)
{
	if (argc != 4)
	{
		std::cerr << "ERROR: invalid number of arguments" << std::endl;
		std::cerr << "<filename> <search> <replace>" << std::endl;
		return (false);
	}
	return (true);
}

/**
 * @brief Checks if a input file exists.
 * 
 * @param in Reference to an input file.
 * @return true When the input file exists and can be opened.
 * @return false When the input file can not be opened.
 */
bool	check_in_file(std::ifstream &in)
{
	if (!in.is_open() || in.fail())
	{
		std::cerr << "ERROR: couldn't open file." << std::endl;
		return (false);
	}
	return (true);
}

/**
 * @brief Checks if a output file exists.
 * 
 * @param out Reference to an output file.
 * @return true When the output file is created.
 * @return false When the output file can not be created.
 */
bool	check_out_file(std::ofstream &out)
{
	if (!out.is_open() || out.fail())
	{
		std::cerr << "ERROR: couldn't create file." << std::endl;
		return (false);
	}
	return (true);
}

/**
 * @brief Checks if the search string is empty.
 * 
 * @param search The string to be search.
 * @return true When the string is empty.
 * @return false When the string is not empty.
 */
bool	search_empty(std::string search)
{
	if (!search.length())
	{
		std::cerr << "ERROR: can't replace an empty string." << std::endl;
		return (true);
	}
	return (false);
}

/**
 * @brief Copies the content of in into a new file out,
 replacing every occurrence of s1 with s2.
 * 
 */
void	replace(std::ifstream &in, std::ofstream &out, std::string s1, \
				std::string s2)
{
	std::string	line;
	while (getline(in, line))
	{
		int	start = 0;
		while (true)
		{
			size_t i = line.find(s1, start);
			if (i == std::string::npos)
				break ;
			out << line.substr(start, i - start) << s2;
			start = i + s1.length();
		}
		out << &line[start] << std::endl;
	}
}
