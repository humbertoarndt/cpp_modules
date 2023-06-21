/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:37:23 by harndt            #+#    #+#             */
/*   Updated: 2023/06/21 18:02:49 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#define SHOW_MSG true

// =============================================================================
// Constructor and Destructor
// =============================================================================

/**
 * @brief Construct a new Presidential Pardon Form:: Presidential Pardon Form object
 * 
 */
PresidentialPardonForm::PresidentialPardonForm(void) :
	AForm("Presidential Pardon Form", PPF_SIGN_GRADE, PPF_EXEC_GRADE)
{
	if (SHOW_MSG == true)
		LOG("👨‍💼📄 Default Constructor called");
	return ;
}

/**
 * @brief Construct a new Presidential Pardon Form:: Presidential Pardon Form object
 * 
 * @param src The object to be copied.
 */
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src)
{
	if (SHOW_MSG == true)
		LOG("👨‍💼📄 Copy Constructor called");
	this->setName(src.getName());
	this->setSign(src.getSign());
	this->setGradeSign(src.getGradeSign());
	this->setGradeExec(src.getGradeExec());
	this->setTarget(src.getTarget());
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) :
	AForm("Presidential Pardon Form", PPF_SIGN_GRADE, PPF_EXEC_GRADE)
{
	if (SHOW_MSG == true)
		LOG("👨‍💼📄 Parameter Constructor called");
	this->setTarget(target);
	return ;
}

/**
 * @brief Destroy the Presidential Pardon Form:: Presidential Pardon Form object
 * 
 */
PresidentialPardonForm::~PresidentialPardonForm(void)
{
	if (SHOW_MSG == true)
		LOG("👨‍💼📄 Destructor called");
	return ;
}

// =============================================================================
// Operator Overload
// =============================================================================

/**
 * @brief Overload for the '=' operator
 * 
 * @param rhs The right hand side varible to be assigned.
 * @return PresidentialPardonForm& A pointer to the assigned PresidentialPardonForm object.
 */
PresidentialPardonForm &PresidentialPardonForm::operator = (PresidentialPardonForm const &rhs)
{
	if (SHOW_MSG == true)
		LOG("👨‍💼📄 Assignment operator called");
	if (this != &rhs)
	{
		this->setName(rhs.getName());
		this->setSign(rhs.getSign());
		this->setGradeSign(rhs.getGradeSign());
		this->setGradeExec(rhs.getGradeExec());
		this->setSign(rhs.getSign());
	}
	return (*this);
}

// =============================================================================
// Member Function
// =============================================================================

/**
 * @brief Pardons a President.
 * 
 * @param executor A Bureaucrat object.
 */
void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	LOG(this->getName() << " has been pardoned by Zaphod Beeblebrox");
}