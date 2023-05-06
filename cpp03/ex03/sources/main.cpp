/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:19:15 by harndt            #+#    #+#             */
/*   Updated: 2023/05/06 12:21:50 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	LOG(PURPLE << "\nCalling Constructors" << EOC);
	DiamondTrap	diamond("Kureijī Daiyamondo");
	DiamondTrap	unbreakeble;
	DiamondTrap d = unbreakeble = diamond;

	LOG(PURPLE << "\nShow Traps' Status" << EOC);
	LOG(diamond);
	
	LOG(PURPLE << "DiamondTrap' Showing Off" << EOC);
	diamond.whoAmI();
	for (int i = 0; i < 3; i++)
		diamond.attack("Kirā Kuīn");

	LOG(PURPLE << "\nShow Traps' Status" << EOC);
	LOG(diamond);

	LOG(PURPLE << "Calling Destructors" << EOC);
	return (0);
}