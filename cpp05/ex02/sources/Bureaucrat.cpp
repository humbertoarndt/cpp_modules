/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:35:54 by harndt            #+#    #+#             */
/*   Updated: 2023/07/10 19:33:21 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define SHOW_MSG true

// =============================================================================
// EXCEPTIONS
// =============================================================================

/**
 * @brief Throws an exception when the '_grade' value is higher than 1.
 * 
 * @return const char* Exception message.
 */
const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Grade is too high, highest grade is 1.";
}

/**
 * @brief Throws an exception when the '_grade' value is lowest than 150.
 * 
 * @return const char* Exception message.
 */
const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Grade is too low, lowest grade is 150.";
}

// =============================================================================
// CONSTRUCTORS AND DESTRUCTOR
// =============================================================================

/**
 * @brief Construct a new Bureaucrat:: Bureaucrat object
 * 
 */
Bureaucrat::Bureaucrat(void)
{
	if (SHOW_MSG == true)
		LOG("⚙️ Default Constructor called");
	const_cast<std::string &>(this->_name) = "Undefined";
	/*
	How to cast const?
	
	const_cast<char *>(x)
	Const casts look like regular typecasts in C++, except that they can only 
	be used for casting away constness (or volatile-ness) but not converting 
	between types or casting down a class hierarchy. 

	https://www.cprogramming.com/tutorial/const_correctness.html
	https://en.cppreference.com/w/cpp/language/const_cast
	*/
	this->_grade = L_GRADE;
	return ;
}

/**
 * @brief Construct a new Bureaucrat:: Bureaucrat object
 * 
 * @param name Bureaucrat's new name
 * @param grade Bureaucrat's new grade
 */
Bureaucrat::Bureaucrat(std::string const &name, int grade)
{
	if (SHOW_MSG == true)
		LOG("⚙️ Parameter Constructor called");
	const_cast<std::string &>(this->_name) = name;
	if (grade < H_GRADE)
		throw	Bureaucrat::GradeTooHighException();
	else if (grade > L_GRADE)
		throw	Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	return ;
}

/**
 * @brief Construct a new Bureaucrat:: Bureaucrat object
 * 
 * @param src The Bureaucrat object to be copied.
 */
Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	if (SHOW_MSG == true)
		LOG("⚙️ Copy Constructor called");
	const_cast<std::string &>(this->_name) = src.getName();
	this->_grade = src.getGrade();
	return ;
}

/**
 * @brief Destroy the Bureaucrat:: Bureaucrat object
 * 
 */
Bureaucrat::~Bureaucrat(void)
{
	if (SHOW_MSG == true)
		LOG("⚙️ Destructor called");
	return ;
}

// =============================================================================
// OPERATOR OVERLOAD
// =============================================================================

/**
 * @brief Overload for the '=' operator
 * 
 * @param rhs The right hand side varible to be assigned.
 * @return Bureaucrat& A pointer to the assigned Bureaucrat object.
 */
Bureaucrat & Bureaucrat::operator = (Bureaucrat const &rhs)
{
	if (SHOW_MSG == true)
		LOG("⚙️ Assignment operator called")
	if (this != &rhs)
	{
		const_cast<std::string &>(this->_name) = rhs.getName();
		this->_grade = rhs.getGrade();
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
std::ostream &operator << (std::ostream &o, Bureaucrat const &i)
{
	(void)i;
	o << "⚙️ Displaying Bureaucrat =====================" << std::endl;
	o << "Name: " << i.getName() << std::endl;
	o << "Grade: " << i.getGrade() << std::endl;
	return (o);
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================

/**
 * @brief Gets the object's _grade.
 * 
 * @return int The object's _grade.
 */
int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

/**
 * @brief Gets the object's _name.
 * 
 * @return std::string The object's _name.
 */
std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

/**
 * @brief Decrements the _grade value, adds one.
 * 
 */
void	Bureaucrat::decrementGrade(void)
{
	if (this->getGrade() == L_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

/**
 * @brief Increments the _grade value, substracts one.
 * 
 */
void	Bureaucrat::incrementGrade(void)
{
	if (this->getGrade() == H_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::signForm(AForm &form)
{
	if (form.getSign())
		return ;
		
	try
	{
		form.beSigned(*this);
		LOG(this->getName() << " signed " << form.getName());
	}
	catch(AForm::GradeTooLowException &e)
	{
		ERROR(this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << ".");
	}
}

/**
 * @brief Checks if a Bureaucrat has grade high enough to execute an AFomr object.
 * 
 * @param form The AForm object to be executed.
 */
void	Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		LOG(this->getName() << " executed " << form.getName());
	}
	catch (AForm::GradeTooLowException &e)
	{
		LOG(this->getName() << " couldn't execute " << form.getName() << " since " << e.what());
	}
}