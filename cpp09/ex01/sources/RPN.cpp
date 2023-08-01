/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:33:39 by harndt            #+#    #+#             */
/*   Updated: 2023/07/26 12:13:11 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#define SHOW_MSG true

// =============================================================================
// Exceptions
// =============================================================================

/**
 * @brief Throws a message when an unexpected input is received.
 * 
 * @return const char* A Message.
 */
const char	*RPN::BadInputException::what(void) const throw()
{
	return (">Error: bad input.");
}

/**
 * @brief Throws a message when a division by zero occurs.
 * 
 * @return const char* A Message.
 */
const char	*RPN::ZeroDivisionException::what(void) const throw()
{
	return (">Error: division by zero.");
}

// =============================================================================
// Constructors and Desctructor
// =============================================================================

/**
 * @brief Construct a new RPN::RPN object.
 * 
 */
RPN::RPN(void)
{
	if (SHOW_MSG == true)
		LOG("RPN Default contructor called.");
	return ;
}

/**
 * @brief Construct a new RPN::RPN object.
 * 
 * @param expression Sequence to be stacked.
 */
RPN::RPN(std::string expression)
{
	if (SHOW_MSG == true)
		LOG("RPN Parameter contructor called.");
	initStack(expression);
	// printStack();
	evaluateExpression();
	return ;
}

/**
 * @brief Construct a new RPN::RPN object.
 * 
 * @param src The object to be copied.
 */
RPN::RPN(RPN const &src)
{
	if (SHOW_MSG == true)
		LOG("RPN Copy contructor called.");
	*this = src;
	return ;
}

/**
 * @brief Destroy the RPN::RPN object.
 * 
 */
RPN::~RPN(void)
{
	if (SHOW_MSG == true)
		LOG("RPN Destructor called.");
	return ;
}

// =============================================================================
// Overload
// =============================================================================

/**
 * @brief Overload for the '=' operator.
 * 
 * @param rhs The right hand side varible to be assigned.
 * @return RPN& A pointer to the assigned RPN object.
 */
RPN &RPN::operator = (RPN const &rhs)
{
	if (SHOW_MSG == true)
		LOG("RPN Assignment Operator Called.");
	if (this != &rhs)
		this->_stack = rhs._stack;
	return (*this);
}

// =============================================================================
// Functions
// =============================================================================

/**
 * @brief Prints the elements in '_stack'.
 * 
 */
void	RPN::printStack(void)
{
	while (!_stack.empty())
	{
		std::cout << static_cast<char>(_stack.top()) << std::endl;
		_stack.pop();
	}
}

/**
 * @brief Pushs only valid elements into '_stack'.
 * 
 * @param expression Sequence to be stacked.
 */
void	RPN::initStack(std::string expression)
{
	std::string::reverse_iterator	it;
	std::string						validElements;

	validElements = " +-*/0123456789";
	for (it = expression.rbegin(); it != expression.rend(); it++)
	{
		if (validElements.find(*it) == std::string::npos)
			throw RPN::BadInputException();
		if (*it != ' ')
			_stack.push(*it);
	}
}

/**
 * @brief Sums two operands.
 * 
 * @param result Stores the result.
 * @param first First operand.
 * @param second Second operand.
 */
void	RPN::sum(int &result, int &first, int &second)
{
	if (second == -1)
	{
		result += first;
		first = -1;
	}
	else
	{
		first += second;
		second = -1;
	}
}

/**
 * @brief Subtracts two operands.
 * 
 * @param result Stores the result.
 * @param first First operand.
 * @param second Second operand.
 */
void	RPN::subtract(int &result, int &first, int &second)
{
	if (second == -1)
	{
		result -= first;
		first = -1;
	}
	else
	{
		first -= second;
		second = -1;
	}
}

/**
 * @brief Multiplies two operands.
 * 
 * @param result Stores the result.
 * @param first First operand.
 * @param second Second operand.
 */
void	RPN::multiply(int &result, int &first, int &second)
{
	if (second == -1)
	{
		result *= first;
		first = -1;
	}
	else
	{
		first *= second;
		second = -1;
	}
}

/**
 * @brief Divides two operands.
 * 
 * @param result Stores the result.
 * @param first First operand.
 * @param second Second operand.
 */
void	RPN::division(int &result, int &first, int &second)
{
	if (second == -1)
	{
		if (first == 0)
			throw RPN::ZeroDivisionException();
		result /= first;
		first = -1;
	}
	else
	{
		if (second == 0)
			throw RPN::ZeroDivisionException();
		first /= second;
		second = -1;
	}
}

/**
 * @brief Based on the operator calculates the rigth operation.
 * 
 * @param result Stores the result.
 * @param first First operand.
 * @param second Second operand.
 * @param op The operator.
 */
void	RPN::calculate(int &result, int &first, int &second, char op)
{
	if (first == -1 && second == -1)
		throw RPN::BadInputException();

	switch(op)
	{
		case '+':
			sum(result, first, second);
			break ;
		case '-':
			subtract(result, first, second);
			break ;
		case '*':
			multiply(result, first, second);
			break ;
		case '/':
			division(result, first, second);
			break ;
		default :
			throw RPN::BadInputException();
			break ;
	}
}

/**
 * @brief Build the expression to be calculated.
 * 
 */
void	RPN::evaluateExpression(void)
{
	unsigned int	count;
	int				result, first, second;

	first = -1;
	second = -1;
	count = 0;
	result = 0;

	while (!_stack.empty())
	{
		if (!std::isdigit(_stack.top()))
			calculate(result, first, second, _stack.top());
		else if (count == 0)
			result = _stack.top() - '0';
		else if (first < 0)
			first = _stack.top() - '0';
		else
			second = _stack.top() - '0';
		_stack.pop();
		count++;
	}
	if (first != -1)
		throw RPN::BadInputException();
	LOG(result);
}