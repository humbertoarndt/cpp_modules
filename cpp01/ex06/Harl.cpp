/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:57:04 by harndt            #+#    #+#             */
/*   Updated: 2023/05/09 11:36:43 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// =============================================================================
// CONTRUCTOR AND DESTRUCTOR
// =============================================================================

/**
 * @brief Construct a new Harl:: Harl object
 * 
 */
Harl::Harl(void)
{
	return ;
}

/**
 * @brief Destroy the Harl:: Harl object
 * 
 */
Harl::~Harl(void)
{
	return ;
}

// =============================================================================
// FUNCTION
// =============================================================================

/**
 * @brief Prints the DEBUG message.
 * 
 */
void	Harl::debug(void)
{
	PRINT("");
	PRINT("[DEBUG]")
	PRINT("I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.");
	PRINT("I really do!");
	PRINT("");
}

/**
 * @brief Prints the INFO message.
 * 
 */
void	Harl::info(void)
{
	PRINT("");
	PRINT("[INFO]")
	PRINT("I cannot believe adding extra bacon costs more money.");
	PRINT("You didn’t put enough bacon in my burger.");
	PRINT("If you did, I wouldn’t be asking for more!");
	PRINT("");
}

/**
 * @brief Prints the WARNING message.
 * 
 */
void	Harl::warning(void)
{
	PRINT("");
	PRINT("[WARNING]")
	PRINT("I think I deserve to have some extra bacon for free.");
	PRINT("I’ve been coming for years whereas you started working here since last month.");
	PRINT("");
}

/**
 * @brief Prints the ERROR message.
 * 
 */
void	Harl::error(void)
{
	PRINT("");
	PRINT("[ERROR]")
	PRINT("This is unacceptable!");
	PRINT("I want to speak to the manager now.");
	PRINT("");
}

/**
 * @brief Prints a message based on the receiv level, or and 'Invalid option'
 id the level doesn't exist.
 * 
 * @param level A String to indicate wich message should be printed.
 */
void	Harl::complain(std::string level)
{
	size_t	index;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*f[4])(void) = {&Harl::debug, &Harl::info,
									&Harl::warning, &Harl::error};
									
	for (index = 0; index < 4; index++)
		if (level == levels[index])
			break ;
	switch (index)
	{
		case (0) :
			(this->*f[index++])();
		case (1) :
			(this->*f[index++])();
		case (2) :
			(this->*f[index++])();
		case (3) :
			(this->*f[index++])();
			break ;
		default :
			ERROR("Invalid option");
			break ;
	}
}
