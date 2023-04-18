/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:57:04 by harndt            #+#    #+#             */
/*   Updated: 2023/04/18 15:55:59 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// =============================================================================
// CONTRUCTOR AND DESTRUCTOR
// =============================================================================

Harl::Harl(void)
{
	return ;
}

Harl::~Harl(void)
{
	return ;
}

// =============================================================================
// FUNCTION
// =============================================================================

void	Harl::debug(void)
{
	PRINT("");
	PRINT("[DEBUG]")
	PRINT("I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.");
	PRINT("I really do!");
	PRINT("");
}

void	Harl::info(void)
{
	PRINT("");
	PRINT("[INFO]")
	PRINT("I cannot believe adding extra bacon costs more money.");
	PRINT("You didn’t put enough bacon in my burger.");
	PRINT("If you did, I wouldn’t be asking for more!");
	PRINT("");
}

void	Harl::warning(void)
{
	PRINT("");
	PRINT("[WARNING]")
	PRINT("I think I deserve to have some extra bacon for free.");
	PRINT("I’ve been coming for years whereas you started working here since last month.");
	PRINT("");
}

void	Harl::error(void)
{
	PRINT("");
	PRINT("[ERROR]")
	PRINT("This is unacceptable!");
	PRINT("I want to speak to the manager now.");
	PRINT("");
}

void	Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "ERROR", "INFO", "WARNING"};
	void	(Harl::*f[4])(void) = {&Harl::debug, &Harl::error,
									&Harl::info, &Harl::warning};
									
	for (size_t i = 0; i < 4; i++)
		if (level == levels[i])
			return((this->*f[i])());
	ERROR("Invalid option");
}
