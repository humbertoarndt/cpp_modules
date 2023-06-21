/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:47:41 by harndt            #+#    #+#             */
/*   Updated: 2023/06/21 17:34:56 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#define SHOW_MSG true

// =============================================================================
// Constructors and Destructor
// =============================================================================

/**
 * @brief Construct a new Robotomy Request Form:: Robotomy Request Form object
 * 
 */
RobotomyRequestForm::RobotomyRequestForm(void) : 
	AForm("Robotomy Request Form", RRF_SIGN_GRADE, RRF_EXEC_GRADE)
{
	if (SHOW_MSG == true)
		LOG("🤖📄 Default Constructor called");
	return ;
}

/**
 * @brief Construct a new Robotomy Request Form:: Robotomy Request Form object
 * 
 * @param src The object to be copied.
 */
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src)
{
	if (SHOW_MSG == true)
		LOG("🤖📄 Copy Constructor called");
	this->setName(src.getName());
	this->setSign(src.getSign());
	this->setGradeSign(src.getGradeSign());
	this->setGradeExec(src.getGradeExec());
	this->setTarget(src.getTarget());
}

/**
 * @brief Construct a new Robotomy Request Form:: Robotomy Request Form object
 * 
 * @param target Target to robotomize.
 */
RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : 
	AForm("Robotomy Request Form", RRF_SIGN_GRADE, RRF_EXEC_GRADE)
{
	if (SHOW_MSG == true)
		LOG("🤖📄 Parameter Constructor called");
	this->setTarget(target);
	return ;
}

/**
 * @brief Destroy the Robotomy Request Form:: Robotomy Request Form object
 * 
 */
RobotomyRequestForm::~RobotomyRequestForm(void)
{
	if (SHOW_MSG == true)
		LOG("🤖📄 Destructor called");
	return ;
}

// =============================================================================
// Operator Overload
// =============================================================================

/**
 * @brief Overload for the '=' operator
 * 
 * @param rhs The right hand side varible to be assigned.
 * @return RobotomyRequestForm& A pointer to the assigned RobotomyRequestForm object.
 */
RobotomyRequestForm & RobotomyRequestForm::operator = (RobotomyRequestForm const &rhs)
{
	if (SHOW_MSG == true)
		LOG("🤖📄 Assignment operator called");
	if (this != &rhs)
	{
		this->setName(rhs.getName());
		this->setSign(rhs.getSign());
		this->setGradeSign(rhs.getGradeSign());
		this->setGradeExec(rhs.getGradeExec());
		this->setTarget(rhs.getTarget());
	}
	return (*this);
}

// =============================================================================
// Member Functions
// =============================================================================

/**
 * @brief When the executor have the required grades, make some drilling noises.
 * Then informs that the '_target' has been robotomized successfully 50% of 
 * time. Otherwise, informs that he robotomy failed.
 * 
 * @param executor A Bureaucrat object.
 */
void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	LOG("\n* some drilling noise *");
	std::srand(std::time(0));
	if (std::rand() % 2)
	{
		LOG(this->getTarget() << " has been robotomized successfully.");
	}
	else
		LOG("Robotomization failed on " << this->getTarget());
}