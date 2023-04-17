/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:05:13 by harndt            #+#    #+#             */
/*   Updated: 2023/04/17 11:18:47 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	// Variable declaration
	std::string	stringVAR = "HI THIS IS BRAIN";
	std::string	*stringPTR = &stringVAR;
	std::string	&stringREF = stringVAR;

	// Printing address
	std::cout << "The memory address of the string variable:\t";
	std::cout << &stringVAR << std::endl;

	std::cout << "The memory address held by stringPTR:\t\t";
	std::cout << stringPTR << std::endl;

	std::cout << "The memory address held by stringREF:\t\t";
	std::cout << &stringREF << std::endl << std::endl;

	// Printing value
	std::cout << "The value of the string variable:\t";
	std::cout << stringVAR << std::endl;

	std::cout << "The value pointed to by stringPTR:\t";
	std::cout << *stringPTR << std::endl;

	std::cout << "The value pointed to by stringREF:\t";
	std::cout << stringREF << std::endl;

	return (0);
}
