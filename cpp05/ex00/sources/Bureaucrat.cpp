/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:35:54 by harndt            #+#    #+#             */
/*   Updated: 2023/06/14 17:28:59 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define SHOW_MSG true

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
Bureaucrat::Bureaucrat(std::string const &name, unsigned int grade)
{
	if (SHOW_MSG == true)
		LOG("⚙️ Parameter Constructor called");
	const_cast<std::string &>(this->_name) = name;
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
	o << "\n⚙️ Displaying Bureaucrat =========================" << std::endl;
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
 * @return unsigned int The object's _grade.
 */
unsigned int	Bureaucrat::getGrade(void) const
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
	/* Implementar via regra */
	if (this->getGrade() != L_GRADE)
		this->_grade++;
}

/**
 * @brief Increments the _grade value, substracts one.
 * 
 */
void	Bureaucrat::incrementGrade(void)
{
	/* Implementar via regra */
	if (this->getGrade() != H_GRADE)
		this->_grade--;
}