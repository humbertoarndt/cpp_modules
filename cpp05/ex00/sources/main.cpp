/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:40:01 by harndt            #+#    #+#             */
/*   Updated: 2023/06/15 12:23:12 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
	TODOS
	[x] Study Throw Exception.
	[x] Create Bureaucrat::GradeTooHighException.
	[x] Create Bureaucrat::GradeTooLowException.
	[x ] Create tests on main.
	[x] Documment code.
	[ ] Study 'const' and 'this'
*/

int	main(void)
{
	std::cout << "\nBureaucrats Constructors ====================" << std::endl;

	Bureaucrat marvin = Bureaucrat("Marvin", 42);
	LOG(marvin);

	std::cout << "Increment/Decrement in Range ================" << std::endl;
	marvin.incrementGrade();
	marvin.incrementGrade();
	marvin.incrementGrade();
	marvin.incrementGrade();
	LOG(marvin);
	marvin.decrementGrade();
	marvin.decrementGrade();
	LOG(marvin);

	std::cout << "Invalid Constructors ========================" << std::endl;
	try
	{
		LOG("Invalid Constructor When Grade is 0");
		marvin = Bureaucrat("Marvin", 0);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		ERROR(e.what());
	}

	try
	{
		LOG("\nInvalid Constructor When Grade is -42");
		marvin = Bureaucrat("Marvin", -42);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		ERROR(e.what());
	}

	try
	{
		LOG("\nInvalid Constructor When Grade is 151");
		marvin = Bureaucrat("Marvin", 151);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		ERROR(e.what());
	}

	try
	{
		LOG("\nInvalid Constructor When Grade is 999");
		marvin = Bureaucrat("Marvin", 999);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		ERROR(e.what());
	}

	std::cout << "\nOut of Bounds Increment =====================" << std::endl;
	try
	{
		LOG("Increment when grade is 1");
		marvin = Bureaucrat("Marvin2", 1);
		marvin.incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		ERROR(e.what());
	}
	
	std::cout << "\nOut of Bounds Decrement =====================" << std::endl;
	try
	{
		LOG("Decrement when grade is 150");
		marvin = Bureaucrat("Marvin", 150);
		marvin.decrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		ERROR(e.what());
	}

	std::cout << "\nBureaucrats Destructors =====================" << std::endl;
	return (0);
}