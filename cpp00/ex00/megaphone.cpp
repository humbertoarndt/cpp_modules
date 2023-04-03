/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:40:28 by harndt            #+#    #+#             */
/*   Updated: 2023/04/03 18:38:58 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/**
 * @brief Main function, the program receives a number of strings and 
 capitalizes it.
 * 
 * @param argc Total number of arguments received by command line.
 * @param argv The arguments received by command line.
 * @return int 0.
 */
int	main(int argc, char **argv)
{
	std::string msg;

	if (argc == 1)
		msg = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	// Loops through each received argument.
	for (int i = 1; i < argc; i++)
	{
		msg.append(argv[i]);
		// Loops through each char in a word.
		for (std::string::iterator c = msg.begin(); c != msg.end(); c++)
			*c = toupper(*c);
		msg.append(" ");
	}
	std::cout << msg << std::endl;
	return (0);
}
