/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:19:57 by harndt            #+#    #+#             */
/*   Updated: 2023/06/07 18:04:12 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// =============================================================================
// INCLUDES
// =============================================================================

#include <iostream>

// =============================================================================
// MACROS
// =============================================================================

#define LOG(x) std::cout << x << std::endl;

class ClapTrap
{
	protected:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

		/* Construtors for derived classes */
		ClapTrap(std::string const &name, int hitPoints, int energyPoints, int attackDamage);
		ClapTrap(int hitPoints, int energyPoints, int attackDamage);

	public:
		/* Orthodox Canonical Form methods*/
		ClapTrap(void);
		ClapTrap(std::string const &name);
		ClapTrap(ClapTrap const &src);
		~ClapTrap(void);
		ClapTrap &operator = (ClapTrap const &rhs);

		/* Getters */
		std::string	getName(void) const;
		int		getHitPoints(void) const;
		int		getEnergyPoints(void) const;
		int		getAttackDamage(void) const;

		/* Setters */
		void	setName(std::string const &name);
		void	setHitPoints(int const hitPoints);
		void	setEnergyPoints(int const energyPoints);
		void	setAttackDamage(int const attackDamage);
		
		/* Member functions */
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

std::ostream & operator << (std::ostream  &o, ClapTrap const &i);