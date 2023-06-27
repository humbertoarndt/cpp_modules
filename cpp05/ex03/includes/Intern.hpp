/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:15:14 by harndt            #+#    #+#             */
/*   Updated: 2023/06/27 14:53:47 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// =============================================================================
// Includes
// =============================================================================

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// =============================================================================
// Class
// =============================================================================

class Intern
{
	public:
		/* Orthodox Canonical Form Methods */
		Intern(void);
		Intern(Intern const &src);
		Intern & operator = (Intern const &rhs);
		~Intern(void);

		AForm	*makeForm(std::string formName, std::string target);
};