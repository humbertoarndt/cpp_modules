/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:15:07 by harndt            #+#    #+#             */
/*   Updated: 2023/06/27 11:11:59 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#define SHOW_MSG true

// =============================================================================
// Constructors and Destructor
// =============================================================================

/**
 * @brief Construct a new Intern:: Intern object
 * 
 */
Intern::Intern(void)
{
	if (SHOW_MSG == true)
		LOG("🧑‍🎓 Default Constructor called");
	return ;
}

/**
 * @brief Construct a new Intern:: Intern object
 * 
 * @param src The Intern object to be copied.
 */
Intern::Intern(Intern const &src)
{
	if (SHOW_MSG == true)
		LOG("🧑‍🎓 Default Constructor called");
	(void)src;
	return ;
}

/**
 * @brief Destroy the Intern:: Intern object
 * 
 */
Intern::~Intern(void)
{
	if (SHOW_MSG == true)
		LOG("🧑‍🎓 Destructor called");
	return ;
}

// =============================================================================
// Operator Overload
// =============================================================================

/**
 * @brief Overload for the '=' operator
 * 
 * @param rhs The right hand side varible to be assigned.
 * @return Intern& A pointer to the assigned Intern object.
 */
Intern & Intern::operator = (Intern const &rhs)
{
	if (SHOW_MSG == true)
		LOG("🧑‍🎓 Assignment operator called");
	(void)rhs;
	return (*this);
}

// =============================================================================
// Member Functions
// =============================================================================

/**
 * @brief It takes two strings to create an AForm.
 * 
 * @param formName The name of the AForm to be created.
 * @param target The target of the AForm to be created.
 * @return AForm* The created AForm.
 */
AForm *Intern::makeForm(std::string formName, std::string target)
{
	t_form	form = NULL;
	
	static	s_form formOptions[3] = 
	{
		{"shrubbery creation", &ShrubberyCreationForm::create},
		{"robotomy request", &RobotomyRequestForm::create},
		{"presidential pardon", &PresidentialPardonForm::create},
	};

	for (int i = 0; i < 3; i++)
	{
		if (formOptions[i].name == formName)
		{
			form = formOptions[i].form;
			break ;
		}
	}

	if (!form)
		throw AForm::FormDoesntExist();

	LOG("> 🧑‍🎓 Created " << formName << " form");
	return (form(target));
}