/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:14:17 by harndt            #+#    #+#             */
/*   Updated: 2023/05/06 11:25:26 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap
{
	public:
		/* Orthodox Canonical Form methods*/
		ScavTrap(void);
		ScavTrap(std::string const &name);
		ScavTrap(ScavTrap const &src);
		~ScavTrap(void);
		ScavTrap &operator = (ScavTrap const &rhs);

		/* Member functions */
		void	attack(const std::string &target);
		void	guardGate(void);
};

std::ostream & operator << (std::ostream  &o, ScavTrap const &i);