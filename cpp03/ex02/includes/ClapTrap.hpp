/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:19:57 by harndt            #+#    #+#             */
/*   Updated: 2023/05/03 13:20:57 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// =============================================================================
// INCLUDES
// =============================================================================

#include <iostream>

// =============================================================================
// COLORS
// =============================================================================

#define EOC		"\033[0m"		// Text Reset
#define BLACK	"\033[0;30m"	// Black
#define RED		"\033[0;31m"	// Red
#define GREEN	"\033[0;32m"	// Green
#define YELLOW	"\033[0;33m"	// Yellow
#define BLUE	"\033[0;34m"	// Blue
#define PURPLE	"\033[0;35m"	// Purple
#define CYAN	"\033[0;36m"	// Cyan
#define WHITE	"\033[0;37m"	// White

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