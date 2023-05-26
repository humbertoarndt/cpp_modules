/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:27:38 by harndt            #+#    #+#             */
/*   Updated: 2023/05/17 15:56:38 by harndt           ###   ########.fr       */
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

// =============================================================================
// CLASS
// =============================================================================

class Animal
{
	protected:
		std::string	type;

	public:
		Animal(void);
		Animal(Animal const &src);
		Animal &operator = (Animal const &rhs);
		~Animal(void);

		std::string	getType(void) const;
		void	makeSound(void) const;
};

std::ostream &operator << (std::ostream &o, Animal const &i);