/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:21:14 by harndt            #+#    #+#             */
/*   Updated: 2023/08/01 11:45:24 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// =============================================================================
// Includes
// =============================================================================

#include <algorithm>	//	std::sort
#include <climits>		//	INT_MAX
#include <cstdlib>		//	std::strtol
#include <deque>		//	std::deque<int>
#include <iostream>		//	std::cout, std::cerr
#include <vector>		//	std::vector<int>
// #include <iomanip>

// =============================================================================
// Macros
// =============================================================================

#define LOG(x) std::cout << x << std::endl;
#define ERROR(x) std::cerr << x << std::endl;

// =============================================================================
// Class
// =============================================================================

class PmergeMe
{
	private:
		/* Vector Attributes */
		std::vector<int>				_vector;
		std::vector<std::vector<int> >	_vectorPairs;
	
	public:
		/* Orthodox Canonical Form methods */
		PmergeMe(void);
		PmergeMe(PmergeMe const &src);
		PmergeMe(int size, char **elements);
		PmergeMe &operator = (PmergeMe const &rhs);
		~PmergeMe(void);

		/* Vector Member Functions */
		void	initVector(int size, char **elements);
		void	printVector(void);
		void	checkDuplicate(void);
		void	getPairs(void);
		void	sortPairs(void);

		/* Exceptions */
		class BadInputException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};