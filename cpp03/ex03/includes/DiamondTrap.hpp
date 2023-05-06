/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:19:50 by harndt            #+#    #+#             */
/*   Updated: 2023/05/06 12:01:44 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;

	public:
		/* Orthodox Canonical Form methods*/
		DiamondTrap(void);
		DiamondTrap(std::string const &name);
		DiamondTrap(DiamondTrap const &src);
		~DiamondTrap(void);
		DiamondTrap &operator = (DiamondTrap const &rhs);	

		/* Get / Set*/
		std::string	getName(void) const;
		void		setName(std::string const &name);

		/* Member functions */
		void	attack(const std::string &target);
		void	whoAmI(void);
};

std::ostream & operator << (std::ostream &o, DiamondTrap const &i);