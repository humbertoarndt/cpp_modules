/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:19:15 by harndt            #+#    #+#             */
/*   Updated: 2023/06/07 18:05:18 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	LOG("\nCalling Constructors");
	DiamondTrap	diamond("Kureijī Daiyamondo");
	DiamondTrap	unbreakeble;
	DiamondTrap d = unbreakeble = diamond;

	LOG("\nShow Traps' Status");
	LOG(diamond);
	
	LOG("DiamondTrap' Showing Off");
	diamond.whoAmI();
	for (int i = 0; i < 3; i++)
		diamond.attack("Kirā Kuīn");

	LOG("\nShow Traps' Status");
	LOG(diamond);

	LOG("Calling Destructors");
	return (0);
}