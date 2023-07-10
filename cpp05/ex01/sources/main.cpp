/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:40:01 by harndt            #+#    #+#             */
/*   Updated: 2023/07/10 18:31:38 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
	TODOS
	[x] Study Throw Exception.
	[x] Create Bureaucrat::GradeTooHighException.
	[x] Create Bureaucrat::GradeTooLowException.
	[x] Create tests on main.
	[x] Documment code.
	[x] Implement beSigned(Bureaucrat const &b) to Form, it changes the status
	when if the Bureaucrat's grade is high enough to sign it, if the grade is
	too low throw a Form::GradeToLowException()
	[x] Implement signForm() to Bureaucratm, if the form is signed prints a 
	message of succes, if not prints a message informing that the bureaucrat 
	can't sign this form.
	[ ] Study 'const' and 'this'
*/

void	testFormGradesHigh(void)
{
	std::cout << "\nTesting Grades Greater than 1 ==============" << std::endl;

	try
	{
		std::cout << "\nTry Form(Humberto, 0, 0)" << std::endl;
		Form f("Humberto", 0, 0);
	}
	catch(Form::GradeTooHighException &e)
	{
		ERROR(e.what());
	}

	try
	{
		std::cout << "\nTry Form(Humberto, 1, 0)" << std::endl;
		Form f("Humberto", 1, 0);
	}
	catch(Form::GradeTooHighException &e)
	{
		ERROR(e.what());
	}

	try
	{
		std::cout << "\nTry Form(Humberto, 0, 1)" << std::endl;
		Form f("Humberto", 0, 1);
	}
	catch(Form::GradeTooHighException &e)
	{
		ERROR(e.what());
	}

	try
	{
		std::cout << "\nTry Form(Humberto, 1, 1)" << std::endl;
		Form f("Humberto", 1, 1);
	}
	catch(Form::GradeTooHighException &e)
	{
		ERROR(e.what());
	}
}

void	testFormGradesLow(void)
{
	std::cout << "\nTesting Grades Lower than 150 ==============" << std::endl;

	try
	{
		std::cout << "\nTry Form(Humberto, 999, 999)" << std::endl;
		Form f("Humberto", 999, 999);
	}
	catch(Form::GradeTooLowException &e)
	{
		ERROR(e.what());
	}

	try
	{
		std::cout << "\nTry Form(Humberto, 150, 999)" << std::endl;
		Form f("Humberto", 150, 999);
	}
	catch(Form::GradeTooLowException &e)
	{
		ERROR(e.what());
	}

	try
	{
		std::cout << "\nTry Form(Humberto, 999, 150)" << std::endl;
		Form f("Humberto", 999, 150);
	}
	catch(Form::GradeTooLowException &e)
	{
		ERROR(e.what());
	}

	try
	{
		std::cout << "\nTry Form(Humberto, 150, 150)" << std::endl;
		Form f("Humberto", 150, 150);
	}
	catch(Form::GradeTooLowException &e)
	{
		ERROR(e.what());
	}
}

int	main(void)
{
	// std::cout << "\nForm Constructors ===========================" << std::endl;
	Form f("Humberto", 32, 52);
	Bureaucrat b("Doisberto", 1);
	// f.beSigned(b);
	b.signForm(f);
	// Form f2("Humberto", 12, 13);
	// Form f3(f2);

	LOG(f);

	// testFormGradesHigh();
	// testFormGradesLow();

	// std::cout << "\nForm Destructors ===========================" << std::endl;
	return (0);
}