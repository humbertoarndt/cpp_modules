/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:35:19 by harndt            #+#    #+#             */
/*   Updated: 2023/06/07 15:52:09 by harndt           ###   ########.fr       */
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

// =============================================================================
// CLASS
// =============================================================================

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		/* Orthodox Canonical Form methods */
		WrongAnimal(void);
		WrongAnimal(std::string const &type);
		WrongAnimal(WrongAnimal const &src);
		WrongAnimal &operator = (WrongAnimal const &rhs);
		~WrongAnimal(void);
		
		/* Member Function */
		std::string	getType(void) const;
		void	makeSound(void) const;
};