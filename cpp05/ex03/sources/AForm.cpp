/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:32:32 by harndt            #+#    #+#             */
/*   Updated: 2023/06/27 14:15:04 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

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
const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return "Grade is too high.";
}

/**
 * @brief Throws an exception when the '_gradeSign' or '_gradeExec'value is 
 * lower than 150.
 * 
 * @return const char* Exception message.
 */
const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return "Grade is too low.";
}

/**
 * @brief Throws an exception when the form is not signed.
 * 
 * @return const char* Exception message.
 */
const char	*AForm::FormNotSignedException::what(void) const throw()
{
	return "Form not signed.";
}

/**
 * @brief Throws an exception when the form is not created.
 * 
 * @return const char* Exception message.
 */
const char	*AForm::FormDoesntExist::what(void) const throw()
{
	return "Form doesn't exist.";
}

// =============================================================================
// CONSTRUCTORS AND DESTRUCTOR
// =============================================================================

/**
 * @brief Construct a new AForm:: AForm object
 * 
 */
AForm::AForm(void) : _gradeSign(L_GRADE), _gradeExec(L_GRADE)
{
	if (SHOW_MSG == true)
		LOG("📄 Default Constructor Called");
	const_cast<std::string &>(this->_name) = "Undefined";
	this->_isSigned = false;
	const_cast<std::string &>(this->_target)= "None";
	return ;
}

/**
 * @brief Construct a new AForm:: AForm object
 * 
 * @param name AForm's name
 * @param gradeSign AForm's gradeSign
 * @param gradeExec AForm's gradeExec
 */
AForm::AForm(std::string const &name, 
	int const &gradeSign, 
	int const &gradeExec) : 
	_gradeSign(gradeSign),
	_gradeExec(gradeExec)
{
	if (SHOW_MSG == true)
		LOG("📄 Parameter Constructor Called");
	const_cast<std::string &>(this->_name) = name;
	this->_isSigned = false;
	const_cast<std::string &>(this->_target)= "None";
	if (this->getGradeSign() > L_GRADE || this->getGradeExec() > L_GRADE)
		throw AForm::GradeTooLowException();
	if (this->getGradeSign() < H_GRADE || this->getGradeExec() < H_GRADE)
		throw AForm::GradeTooHighException();
	return ;
}

/**
 * @brief Construct a new AForm:: AForm object
 * 
 * @param src The AForm object to copied.
 */
AForm::AForm(AForm const &src) : _gradeSign(src.getGradeSign()), _gradeExec(src.getGradeExec())
{
	if (SHOW_MSG == true)
		LOG("📄 Copy Constructor Called");
	const_cast<std::string &>(this->_name) = src.getName();
	this->_isSigned = src.getSign();
	const_cast<std::string &>(this->_target) = src.getTarget();
	return ;
}

/**
 * @brief Destroy the Form:: Form object
 * 
 */
AForm::~AForm(void)
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
AForm & AForm::operator = (AForm const &rhs)
{
	if (SHOW_MSG == true)
		LOG("📄 Assignment operator called");
	if (this != &rhs)
	{
		const_cast<std::string &>(this->_name) = rhs.getName();
		this->_isSigned = rhs.getSign();
		const_cast<int &>(this->_gradeSign) = rhs.getGradeSign();
		const_cast<int &>(this->_gradeExec) = rhs.getGradeExec();
		const_cast<std::string &>(this->_target) = rhs.getTarget();
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
std::ostream &operator << (std::ostream &o, AForm const &i)
{
	(void)i;
	o << "\n📄 Displaying Form =====================" << std::endl;
	o << "Name: " << i.getName() << std::endl;
	o << "Signed: " << (i.getSign() ? "True" : "False") << std::endl;
	o << "Signature Grade: " << i.getGradeSign() << std::endl;
	o << "Execution Grade: " << i.getGradeExec();
	return (o);
}

// =============================================================================
// Getters
// =============================================================================

/**
 * @brief Get's the object '_name'.
 * 
 * @return std::string  The object's '_name'.
 */
std::string	AForm::getName(void) const
{
	return (this->_name);
}

/**
 * @brief Get's the object '_isSigned'.
 * 
 * @return true 
 * @return false 
 */
bool	AForm::getSign(void) const
{
	return (this->_isSigned);
}

/**
 * @brief Get's the object '_gradeSign'.
 * 
 * @return int The object '_gradeSign'.
 */
int	AForm::getGradeSign(void) const
{
	return (this->_gradeSign);
}

/**
 * @brief Get's the object '_gradeExec'.
 * 
 * @return int The object '_gradeExec'.
 */
int	AForm::getGradeExec(void) const
{
	return (this->_gradeExec);
}

/**
 * @brief Get's the object '_gradeExec'.
 * 
 * @return int The object '_gradeExec'.
 */
std::string	AForm::getTarget(void) const
{
	return (this->_target);
}

// =============================================================================
// Setters
// =============================================================================

/**
 * @brief Sets a new '_name'.
 * 
 * @param name New name.
 */
void	AForm::setName(std::string const name)
{
	const_cast<std::string &>(this->_name) = name;
}

/**
 * @brief Sets a new '_isSigned'.
 * 
 * @param sign New sign.
 */
void	AForm::setSign(bool const sign)
{
	const_cast<bool &>(this->_isSigned) = sign;
}

/**
 * @brief Sets a new '_gradeSign'.
 * 
 * @param grade New Grade Signature.
 */
void	AForm::setGradeSign(int const grade)
{
	const_cast<int &>(this->_gradeSign) = grade;
}

/**
 * @brief Sets a new '_gradeExec'.
 * 
 * @param grade New Grade Execution.
 */
void	AForm::setGradeExec(int const grade)
{
	const_cast<int &>(this->_gradeExec) = grade;
}

/**
 * @brief Sets a new '_target'.
 * 
 * @param grade New Target.
 */
void	AForm::setTarget(std::string const target)
{
	const_cast<std::string &>(this->_target) = target;
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================

/**
 * @brief Changes the status of a AForm to 'true'.
 * 
 * @param bureaucrat The object to check a Form.
 */
void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeSign())
		throw AForm::GradeTooLowException();
	else
		this->_isSigned = true;
}

/**
 * @brief Checks if an AForm can be executed, and executes it.
 * 
 * @param executor The Bureaucrat responsible for executing the AForm objetc.
 */
void	AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	if (!this->getSign())
		throw AForm::FormNotSignedException();
}