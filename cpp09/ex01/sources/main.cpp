/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:10:23 by harndt            #+#    #+#             */
/*   Updated: 2023/07/25 16:15:26 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		ERROR("usage: ./RPN <number> <number> <number> <number>");
		return (1);
	}
	RPN	rpn(argv[1]);
	return (0);
}