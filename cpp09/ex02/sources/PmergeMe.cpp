/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:25:20 by harndt            #+#    #+#             */
/*   Updated: 2023/08/04 14:52:11 by harndt           ###   ########.fr       */
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
		LOG("PmergeMe Parameter constructor called.");
	
	/* Validate Elements */
	checkSize(size);
	checkInput(size, elements);
	// checkDuplicates(size, elements);

	/* Vector */
	gettimeofday(&_vectorStart, NULL);
	initVector(size, elements);
	getPairs();
	sortPairs();
	sortPairsVector();
	fillVector();
	fillSortedVector();
	gettimeofday(&_vectorEnd, NULL);

	/* Deque */
	gettimeofday(&_dequeStart, NULL);
	initDeque(size, elements);
	getPairsDeque();
	sortPairsDeque();
	sortPairsDequeLargest();
	fillDeque();
	fillSortedDeque();
	gettimeofday(&_dequeEnd, NULL);

	/* Show Log */
	showLog();
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

	std::cout << "Vector\t[";
	for (; it != end; it++)
		std::cout << *it << ", ";
	LOG(_vector.back() << "]");
}

/**
 * @brief Prints '_sortedVector'.
 * 
 */
void	PmergeMe::printSortedVector(void)
{
	std::vector<int>::iterator	it = _sortedVector.begin();
	std::vector<int>::iterator	end = _sortedVector.end() - 1;

	std::cout << "Vector\t[";
	for (; it != end; it++)
		std::cout << *it << ", ";
	LOG(_sortedVector.back() << "]");
}

/**
 * @brief Breakes '_vector' in small pairs vectors.
 * 
 */
void	PmergeMe::getPairs(void) // ok
{
	int					pair;
	std::vector<int>	*temp;

	pair = 1;
	temp = new std::vector<int>;
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
	{
		temp->push_back(*it);
		if (pair % 2 == 0)
		{
			_vectorPairs.push_back(*temp);
			delete temp;
			temp = new std::vector<int>;
		}
		pair++;
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
void	PmergeMe::sortPairs(void) //ok
{
	for (size_t i = 0; i < _vectorPairs.size(); i++)
		std::sort(_vectorPairs[i].begin(), _vectorPairs[i].end());
}

/**
 * @brief Sort a vector of pairs.
 * 
 */
void	PmergeMe::sortPairsVector(void)
{
	for (size_t i = 0; i < _vectorPairs.size() - 1; i++)
		for (size_t j = i + 1; j < _vectorPairs.size(); j++)
			if (_vectorPairs[i][1] > _vectorPairs[j][1])
				_vectorPairs[i].swap(_vectorPairs[j]);
}

/**
 * @brief Fill '_sortedVector'.
 * 
 */
void	PmergeMe::fillVector(void)
{
	for (size_t i = 0; i < _vectorPairs.size(); i++)
	{
		_auxVector.push_back(_vectorPairs[i][0]);
		_sortedVector.push_back(_vectorPairs[i][1]);
	}
}

/**
 * @brief Fills and sorts '_sortedVector'.
 * 
 */
void	PmergeMe::fillSortedVector(void)
{
	for (std::vector<int>::iterator	aux_it = _auxVector.begin(); aux_it < _auxVector.end(); aux_it++)
	{
		for (std::vector<int>::iterator	sorted_it = _sortedVector.begin(); sorted_it <= _sortedVector.end(); sorted_it++)
		{
			if (*aux_it < *sorted_it)
			{
				_sortedVector.insert(sorted_it, *aux_it);
				break ;
			}
			else if (sorted_it == _sortedVector.end())
				_sortedVector.push_back(*aux_it);
		}
	}
	if (_sortedVector[0] < 0)
	{
		LOG("entrei");
		_sortedVector.erase(_sortedVector.begin());
	}
}

// =============================================================================
// Deque Member Functions
// =============================================================================

/**
 * @brief Initates '_deque' with the values received by command line.
 * 
 * @param size Number of elements received by command line.
 * @param elements Elements received by command line.
 */
void	PmergeMe::initDeque(int size ,char** elements)
{
	int	cur_value;

	for (int i = 0; i < (size - 1); i++)
	{
		cur_value = std::strtol(elements[i + 1], NULL, 10);
		if (cur_value < 0 || cur_value > INT_MAX)
			throw PmergeMe::BadInputException();
		_deque.push_back(cur_value);
	}
}

/**
 * @brief Prints '_deque'.
 * 
 */
void	PmergeMe::printDeque(void)
{
	std::deque<int>::iterator	it = _deque.begin();
	std::deque<int>::iterator	end = _deque.end() - 1;

	std::cout << "Deque\t[";
	for (; it != end; it++)
		std::cout << *it << ", ";
	LOG(_deque.back() << "]");
}

/**
 * @brief Prints '_sortedDeque'.
 * 
 */
void	PmergeMe::printSortedDeque(void)
{
	std::deque<int>::iterator	it = _sortedDeque.begin();
	std::deque<int>::iterator	end = _sortedDeque.end() - 1;

	std::cout << "Deque\t[";
	for (; it != end; it++)
		std::cout << *it << ", ";
	LOG(_sortedDeque.back() << "]");
}

/**
 * @brief Breakes '_deque' in small pairs deque.
 * 
 */
void	PmergeMe::getPairsDeque(void)
{
	int					pair;
	std::deque<int>		*temp;

	pair = 1;
	temp = new std::deque<int>;
	for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); it++)
	{
		temp->push_back(*it);
		if (pair % 2 == 0)
		{
			_dequePairs.push_back(*temp);
			delete temp;
			temp = new std::deque<int>;
		}
		pair++;
	}

	if (temp->size() == 1)
	{
		temp->push_back(-1);
		_dequePairs.push_back(*temp);
	}
	delete temp;
}

/**
 * @brief Sort the pairs from '_deque'.
 * 
 */
void	PmergeMe::sortPairsDeque(void)
{
	for (size_t i = 0; i < _dequePairs.size(); i++)
		std::sort(_dequePairs[i].begin(), _dequePairs[i].end());
}

/**
 * @brief Sort a deque of pairs.
 * 
 */
void	PmergeMe::sortPairsDequeLargest(void)
{
	for (size_t i = 0; i < _dequePairs.size() - 1; i++)
		for (size_t j = i + 1; j < _dequePairs.size(); j++)
			if (_dequePairs[i][1] > _dequePairs[j][1])
				_dequePairs[i].swap(_dequePairs[j]);
}

/**
 * @brief Fill '_sortedDeque'.
 * 
 */
void	PmergeMe::fillDeque(void)
{
	for (size_t i = 0; i < _dequePairs.size(); i++)
	{
		_auxDeque.push_back(_dequePairs[i][0]);
		_sortedDeque.push_back(_dequePairs[i][1]);
	}
}

/**
 * @brief Fills and sorts '_sortedDeque'.
 * 
 */
void	PmergeMe::fillSortedDeque(void)
{
	for (std::deque<int>::iterator	aux_it = _auxDeque.begin(); aux_it < _auxDeque.end(); aux_it++)
	{
		for (std::deque<int>::iterator	sorted_it = _sortedDeque.begin(); sorted_it <= _sortedDeque.end(); sorted_it++)
		{
			if (*aux_it < *sorted_it)
			{
				_sortedDeque.insert(sorted_it, *aux_it);
				break ;
			}
			else if (sorted_it == _sortedDeque.end())
				_sortedDeque.push_back(*aux_it);
		}
	}
	if (_sortedDeque[0] < 0)
		_sortedDeque.erase(_sortedDeque.begin());
}

// =============================================================================
// Member Functions
// =============================================================================

/**
 * @brief Checks the size of the received input.
 * 
 * @param size 
 */
void	PmergeMe::checkSize(int size)
{
	if (size < 2)
		throw PmergeMe::BadInputException();
}

/**
 * @brief Checks if the receive elements are only digits.
 * 
 * @param size The total number of elements receveid.
 * @param elements The received elements.
 */
void	PmergeMe::checkInput(int size, char **elements)
{
	for (int i = 1; i < size; i++)
		for (int j = 0; elements[i][j] != '\0'; j++)
			if (!std::isdigit(elements[i][j]))
				throw PmergeMe::BadInputException();
}

/**
 * @brief Checks if the receive elements contains a duplicate.
 * 
 * @param size The total number of elements receveid.
 * @param elements The received elements.
 */
void	PmergeMe::checkDuplicates(int size, char **elements)
{
	for (int i = 1; i < size; i++)
		for (int j = i + 1; j < size; j++)
			if (*elements[i] == *elements[j])
				throw PmergeMe::BadInputException();
}

/**
 * @brief Calculates the time to sort the vector and the deque, and prints
 * a message on the terminal.
 * 
 */
void	PmergeMe::showLog(void)
{
	double	vClock;
	vClock = (_vectorEnd.tv_sec - _vectorStart.tv_sec) * (double)1000000;
	vClock = (vClock + (_vectorEnd.tv_usec - _vectorStart.tv_usec));
	
	double	dClock;
	dClock = (_dequeEnd.tv_sec - _dequeStart.tv_sec) * (double)1000000;
	dClock = (dClock + (_dequeEnd.tv_usec - _dequeStart.tv_usec));

	LOG(MAGENTA << "Before:");
	printVector();
	printDeque();
	
	LOG(MAGENTA << "After:");
	printSortedVector();
	printSortedDeque();

	LOG("Time to process a range of " << std::fixed << std::setprecision(6) << _vector.size() << " elements with std::vector => " << vClock << " us");
	LOG("Time to process a range of " << std::fixed << std::setprecision(6) <<  _deque.size() << " elements with std::dequeu => " << dClock << " us");
}