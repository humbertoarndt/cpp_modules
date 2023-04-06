/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:22:29 by harndt            #+#    #+#             */
/*   Updated: 2023/04/06 17:32:16 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iostream>
#include <string>

int	PhoneBook::ft_stoi(std::string str)
{
	std::stringstream	ss;
	int					num;

	ss << str;
	ss >> num;
	return (num);
}

int	main(void)
{
	std::string	cmd;
	PhoneBook	phonebook;

	std::cout << " ---------------------" << std::endl;
	std::cout << "|  ^ ^     Welcome    |" << std::endl;
	std::cout << "| (O,O)      to       |" << std::endl;
	std::cout << "| (   )   PhoneBook   |" << std::endl;
	std::cout << " ---------------------" << std::endl;
	while (cmd != EXIT)
	{
		std::cout << "Please chose one of the following options:" << std::endl;
		std::cout << "\t<ADD> to add a new contact into the PhoneBook." << std::endl;
		std::cout << "\t<SEARCH> to look for a contact into the PhoneBook." << std::endl;
		std::cout << "\t<EXIT> to quit the program." << std::endl << "> ";

		std::getline(std::cin, cmd);
		if (cmd == ADD)
			phonebook.prompt_add();
		else if (cmd == SEARCH)
			phonebook.prompt_search();
		else if (cmd != EXIT)
			std::cout << "Command <" << cmd << "> is invalid" << std::endl;
	}
	std::cout << "Quitting the program." <<std::endl;
	return (0);
}