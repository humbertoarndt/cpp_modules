/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:46:30 by harndt            #+#    #+#             */
/*   Updated: 2023/04/18 15:35:40 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/**
 * @brief Checks if the argument counter is valid.
 * 
 * @param argc The argument counter received by command line.
 * @return true When is valid.
 * @return false When is invalid.
 */
bool	check_args(int argc)
{
	if (argc != 2)
	{
		ERROR("Usage <./harl> <level>");
		return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	Harl	harl;

	if (!check_args(argc))
		return (1);
	harl.complain(argv[1]);
	return (0);
}