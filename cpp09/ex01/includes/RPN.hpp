/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:10:02 by harndt            #+#    #+#             */
/*   Updated: 2023/07/27 20:30:26 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// =============================================================================
// Includes
// =============================================================================

#include <iostream>	//std::cout, std::cerr
#include <stack>	//std::stack<int>

// =============================================================================
// Macros
// =============================================================================

#define LOG(x) std::cout << x << std::endl;
#define ERROR(x) std::cerr << x << std::endl;

// =============================================================================
// Class
// =============================================================================

/* What is RPN?
The Reverse Polish Notation (RPN) refers to the mathematical notation where the 
operands (numerical values) are written first, followed by the operators. The 
main aim of this notation is to eliminate ambiguity, simplify evaluation, 
efficient memory utilization, and reduce parsing complexity.

https://www.wallstreetmojo.com/reverse-polish-notation/

Tester
https://www.dcode.fr/reverse-polish-notation
*/

class RPN
{
	private:
		std::stack<int>	_stack;

		/* Member Functions */
		void	initStack(std::string expression);
		void	printStack(void);
		void	evaluateExpression(void);
		void	calculate(int &result, int &first, int &second, char op);
		void	sum(int &result, int &first, int &second);
		void	subtract(int &result, int &first, int &second);
		void	multiply(int &result, int &first, int &second);
		void	division(int &result, int &first, int &second);

	public:
		/* Orthodox Canonical Form methods */
		RPN(void);
		RPN(std::string expression);
		RPN(RPN const &src);
		RPN &operator = (RPN const &rhs);
		~RPN(void);

		/* Exceptions */
		class BadInputException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class ZeroDivisionException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};