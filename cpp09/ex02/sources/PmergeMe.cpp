/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:25:20 by harndt            #+#    #+#             */
/*   Updated: 2023/08/01 11:49:22 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#define SHOW_MSG true

// =============================================================================
// Exceptions
// =============================================================================

/**
 * @brief Throws a message when an unexpected input is received.
 * 
 * @return const char* A Message.
 */
const char	*PmergeMe::BadInputException::what(void) const throw()
{
	return (">Error: bad input.");
}

// =============================================================================
// Constructors and Destructor
// =============================================================================

/**
 * @brief Construct a new Pmerge Me:: Pmerge Me object
 * 
 */
PmergeMe::PmergeMe(void)
{
	if (SHOW_MSG == true)
		LOG("PmergeMe Default constructor called.")
	return ;
}

/**
 * @brief Construct a new Pmerge Me:: Pmerge Me object
 * 
 * @param src the object to be copied.
 */
PmergeMe::PmergeMe(PmergeMe const &src)
{
	if (SHOW_MSG == true)
		LOG("PmergeMe Copy constructor called.")
	*this = src;
	return ;
}

/**
 * @brief Construct a new Pmerge Me:: Pmerge Me object
 * 
 * @param size Number of elements received by command line.
 * @param elements Elements received by command line.
 */
PmergeMe::PmergeMe(int size, char **elements)
{
	if (SHOW_MSG == true)
		LOG("PmergeMe Parameter constructor called.")
	if (size < 2)
		throw PmergeMe::BadInputException();
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; elements[i][j] != '\0'; j++)
		{
			if (!std::isdigit(elements[i][j]))
				throw PmergeMe::BadInputException();
		}
	}

	/* Vector */
	initVector(size, elements);
	printVector();
	checkDuplicate();
	getPairs();
	sortPairs();
}

/**
 * @brief Destroy the Pmerge Me:: Pmerge Me object
 * 
 */
PmergeMe::~PmergeMe(void)
{
	if (SHOW_MSG == true)
		LOG("PmergeMe Destructor called.")
	return ;
}

// =============================================================================
// Overload
// =============================================================================

/**
 * @brief Overload for the '=' operator.
 * 
 * @param rhs The right hand side varible to be assigned.
 * @return PmergeMe& A pointer to the assigned PmergeMe object.
 */
PmergeMe	&PmergeMe::operator = (PmergeMe const &rhs)
{
	if (SHOW_MSG == true)
		LOG("RPN Assignment Operator Called.");
	(void)rhs;
	return (*this);
}

// =============================================================================
// Vector Member Functions
// =============================================================================

/**
 * @brief Initates '_vector' with the values received by command line.
 * 
 * @param size Number of elements received by command line.
 * @param elements Elements received by command line.
 */
void	PmergeMe::initVector(int size, char **elements)
{
	int	cur_value;

	for (int i = 0; i < (size - 1); i++)
	{
		cur_value = std::strtol(elements[i + 1], NULL, 10);
		if (cur_value < 0 || cur_value > INT_MAX)
			throw PmergeMe::BadInputException();
		_vector.push_back(cur_value);
	}
}

/**
 * @brief Prints '_vector'.
 * 
 */
void	PmergeMe::printVector(void)
{
	std::vector<int>::iterator	it = _vector.begin();
	std::vector<int>::iterator	end = _vector.end() - 1;

	std::cout << "[";
	for (; it != end; it++)
		std::cout << *it << ", ";
	LOG(_vector.back() << "]");
}

/**
 * @brief Looks for duplicates in '_vector'.
 * 
 */
void	PmergeMe::checkDuplicate(void)
{
	for (std::size_t i = 0; i < _vector.size(); i++)
		for (std::size_t j = i + 1; j < _vector.size(); j++)
			if (_vector[i] == _vector[j])
				throw PmergeMe::BadInputException();
	return ;
}

/**
 * @brief Breakes '_vector' in small pairs vectors.
 * 
 */
void	PmergeMe::getPairs(void)
{
	std::vector<int>	*temp;
	int					check;

	check = 1;
	temp = new std::vector<int>;
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
	{
		temp->push_back(*it);
		if (check % 2 == 0)
		{
			_vectorPairs.push_back(*temp);
			delete temp;
			temp = new std::vector<int>;
		}
		check++;
	}

	if (temp->size() == 1)
	{
		temp->push_back(-1);
		_vectorPairs.push_back(*temp);
	}
	delete temp;
}

/**
 * @brief Sort the pairs from '_vector'.
 * 
 */
void	PmergeMe::sortPairs(void)
{
	for (size_t i = 0; i < _vectorPairs.size(); i++)
		std::sort(_vectorPairs[i].begin(), _vectorPairs[i].end());
}