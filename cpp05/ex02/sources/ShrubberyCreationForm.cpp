/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:42:39 by harndt            #+#    #+#             */
/*   Updated: 2023/06/21 14:33:11 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#define SHOW_MSG true

// =============================================================================
// Exceptions
// =============================================================================

/**
 * @brief Throws an exception when the output file is not created.
 * 
 * @return const char* Exception message.
 */
const char	*ShrubberyCreationForm::FileCreateErrorException::what(void) const throw()
{
	return "Error, file not created.";
}

// =============================================================================
// Constructors and Destructor
// =============================================================================

/**
 * @brief Construct a new Shrubbery Creation Form:: Shrubbery Creation Form object
 * 
 */
ShrubberyCreationForm::ShrubberyCreationForm(void) : 
	AForm("Shrubbery Creation Form", SCF_SIGN_GRADE, SCF_EXEC_GRADE)
{
	if (SHOW_MSG == true)
		LOG("🌳📄 Default Constructor called");
	return ;
}

/**
 * @brief Construct a new Shrubbery Creation Form:: Shrubbery Creation Form object
 * 
 * @param src The object to be copied.
 */
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src)
{
	if (SHOW_MSG == true)
		LOG("🌳📄 Copy Constructor called");
	this->setName(src.getName());
	this->setSign(src.getSign());
	this->setGradeSign(src.getGradeSign());
	this->setGradeExec(src.getGradeExec());
	this->setTarget(src.getTarget());
	return ;
}

/**
 * @brief Construct a new Shrubbery Creation Form:: Shrubbery Creation Form object
 * 
 * @param target Target to create file with a tree.
 */
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) :
	AForm("Shrubbery Creation Form", SCF_SIGN_GRADE, SCF_EXEC_GRADE)
{
	if (SHOW_MSG == true)
		LOG("🌳📄 Parameter Constructor Called");
	this->setTarget(target);
	return ;
}

/**
 * @brief Destroy the Shrubbery Creation Form:: Shrubbery Creation Form object
 * 
 */
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	if (SHOW_MSG == true)
		LOG("🌳📄 Destructor called");
	return ;
}

// =============================================================================
// Operator Overload
// =============================================================================

/**
 * @brief Overload for the '=' operator
 * 
 * @param rhs The right hand side varible to be assigned.
 * @return ShrubberyCreationForm& A pointer to the assigned ShrubberyCreationForm object.
 */
ShrubberyCreationForm &ShrubberyCreationForm::operator = (ShrubberyCreationForm const &rhs)
{
	if (SHOW_MSG == true)
		LOG("🌳📄 Assignment operator called");
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
 * @brief When the executor have the required grades, creates a file with and
 * writes an ASCII tree inside it.
 * 
 * @param executor A Bureaucrat object.
 */
void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string		filename;
	std::ofstream	outfile;
	AForm::execute(executor);

	filename = this->getTarget() + "_shrubbery";
	std::ofstream out(filename.c_str());
	if (!out.is_open() || out.fail())
		throw ShrubberyCreationForm::FileCreateErrorException();
	outfile.open(filename.c_str());
	outfile << SHRUBBERY;
	LOG(filename << " created with success.");
	outfile.close();
	out.close();
}