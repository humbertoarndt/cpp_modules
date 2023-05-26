/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:25:41 by harndt            #+#    #+#             */
/*   Updated: 2023/05/17 15:58:24 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

int	main(void)
{
	Animal	dog;

	std::cout << dog << std::endl;
	std::cout << dog.getType() << std::endl;
	dog.makeSound();
	return(0);
}