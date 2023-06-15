/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:32:32 by harndt            #+#    #+#             */
/*   Updated: 2023/06/15 19:38:25 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#define SHOW_MSG true

// =============================================================================
// EXCEPTIONS
// =============================================================================

/**
 * @brief Throws an exception when the '_gradeSign' or '_gradeExec' value are 
 * higher than 1.
 * 
 * @return const char* Exception message.
 */
const char	*Form::GradeTooHighException::what(void) const throw()
{
	return "Grade is too high.";
}

/**
 * @brief Throws an exception when the '_gradeSign' or '_gradeExec'value is 
 * lower than 150.
 * 
 * @return const char* Exception message.
 */
const char	*Form::GradeTooLowException::what(void) const throw()
{
	return "Grade is too low.";
}

// =============================================================================
// CONSTRUCTORS AND DESTRUCTOR
// =============================================================================

/**
 * @brief Construct a new Form:: Form object
 * 
 */
Form::Form(void) : _gradeSign(L_GRADE), _gradeExec(L_GRADE)
{
	if (SHOW_MSG == true)
		LOG("📄 Default Constructor Called");
	const_cast<std::string &>(this->_name) = "Undefined";
	this->_isSigned = false;
	return ;
}

/**
 * @brief Construct a new Form:: Form object
 * 
 * @param name Form's name
 * @param gradeSign Form's gradeSign
 * @param gradeExec Form's gradeExec
 */
Form::Form(std::string const &name, 
	int const &gradeSign, 
	int const &gradeExec) : 
	_gradeSign(gradeSign),
	_gradeExec(gradeExec)
{
	if (SHOW_MSG == true)
		LOG("📄 Parameter Constructor Called");
	const_cast<std::string &>(this->_name) = name;
	this->_isSigned = false;
	if (this->getGradeSign() > L_GRADE || this->getGradeExec() > L_GRADE)
		throw Form::GradeTooLowException();
	if (this->getGradeSign() < H_GRADE || this->getGradeExec() < H_GRADE)
		throw Form::GradeTooHighException();
	return ;
}

/**
 * @brief Construct a new Form:: Form object
 * 
 * @param src The Form object to copied.
 */
Form::Form(Form const &src) : _gradeSign(src.getGradeSign()), _gradeExec(src.getGradeExec())
{
	if (SHOW_MSG == true)
		LOG("📄 Copy Constructor Called");
	const_cast<std::string &>(this->_name) = src.getName();
	this->_isSigned = src.getSigned();
	return ;
}

/**
 * @brief Destroy the Form:: Form object
 * 
 */
Form::~Form(void)
{
	if (SHOW_MSG == true)
		LOG("📄 Destructor Called");
	return ;
}

// =============================================================================
// OPERATOR OVERLOAD
// =============================================================================

/**
 * @brief Overload for the '=' operator
 * 
 * @param rhs The right hand side varible to be assigned.
 * @return Form& A pointer to the assigned Form object.
 */
Form & Form::operator = (Form const &rhs)
{
	if (SHOW_MSG == true)
		LOG("📄 Assignment operator called");
	if (this != &rhs)
	{
		const_cast<std::string &>(this->_name) = rhs.getName();
		this->_isSigned = rhs.getSigned();
		const_cast<int &>(this->_gradeSign) = rhs.getGradeSign();
		const_cast<int &>(this->_gradeExec) = rhs.getGradeExec();
	}
	return (*this);
}

/**
 * @brief Overload for the 'std::onstream <<' operator.
 * 
 * @param o Output stream
 * @param i Input stream
 * @return std::ostream& Reference to the output.
 */
std::ostream &operator << (std::ostream &o, Form const &i)
{
	(void)i;
	o << "\n📄 Displaying Bureaucrat =====================" << std::endl;
	o << "Name: " << i.getName() << std::endl;
	o << "Signed: " << (i.getSigned() ? "True" : "False") << std::endl;
	o << "Signature Grade: " << i.getGradeSign() << std::endl;
	o << "Execution Grade: " << i.getGradeExec();
	return (o);
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================

/**
 * @brief Get's the object '_name'.
 * 
 * @return std::string  The object's '_name'.
 */
std::string	Form::getName(void) const
{
	return (this->_name);
}

/**
 * @brief Get's the object '_isSigned'.
 * 
 * @return true 
 * @return false 
 */
bool	Form::getSigned(void) const
{
	return (this->_isSigned);
}

/**
 * @brief Get's the object '_gradeSign'.
 * 
 * @return int The object '_gradeSign'.
 */
int	Form::getGradeSign(void) const
{
	return (this->_gradeSign);
}

/**
 * @brief Get's the object '_gradeExec'.
 * 
 * @return int The object '_gradeExec'.
 */
int	Form::getGradeExec(void) const
{
	return (this->_gradeExec);
}

/**
 * @brief Changes the status of a Form to 'true'.
 * 
 * @param bureaucrat The object to check a Form.
 */
void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeSign())
		throw Form::GradeTooLowException();
	else
		this->_isSigned = true;
}