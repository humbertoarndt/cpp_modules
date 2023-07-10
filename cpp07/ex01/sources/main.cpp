/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:25:44 by harndt            #+#    #+#             */
/*   Updated: 2023/07/10 15:42:06 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	int			arr1[] = {1, 2, 3, 4, 5, 6, 7, 8};
	char		arr2[] = {'h','u','m','b','e','r','t','o'};
	std::string	arr3[] = {"Humberto", "Doisberto", "Trêsberto", "Quatroberto"};

	std::cout << YELLOW << "> Int" << RESET_COLOR << std::endl;
	iter(arr1, sizeof(arr1)/sizeof(int), print);
	
	std::cout << YELLOW << "\n> Char" << RESET_COLOR << std::endl;
	iter(arr2, sizeof(arr2)/sizeof(char), print);

	std::cout << YELLOW << "\n> String" << RESET_COLOR << std::endl;
	iter(arr3, sizeof(arr3)/sizeof(std::string), print);

	return (0);
}
