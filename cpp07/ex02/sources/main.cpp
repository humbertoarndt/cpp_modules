/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:36:45 by harndt            #+#    #+#             */
/*   Updated: 2023/07/12 15:23:16 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#define SIZE 666

/**
 * @brief Creates and tests Array<int>
 * 
 */
void	testInt(void)
{
	LOG("\n> Testing Int " << std::setw(45) << std::setfill('>') << "");
	LOG("> Constructors " << std::setw(44) << std::setfill('>') << "");
	Array<int>			numbers(SIZE);
	int					*control = new int[SIZE];

	std::srand(time(NULL));
	
	for (int i = 0; i < SIZE; i++)
	{
		int const	value = std::rand();
		numbers[i] = value;
		control[i] = value;
	}

	Array<int>			cpy = numbers;
	Array<int>			assign;
	assign = numbers;

	LOG("\n> Size check");
	if (numbers.size() == cpy.size() && 
		numbers.size() == assign.size() && 
		cpy.size() == assign.size())
	{
		LOG("Array<int> numbers[" << numbers.size() << "]");
		LOG("Array<int> cpy[" << cpy.size() << "]");
		LOG("Array<int> assign[" << assign.size() << "]");
		LOG("");
	}
	else
	{
		LOG("Sizes don't match!");
	}

	LOG("> Position check");
	bool	errorFlag = false;
	for (int i = 0; i < SIZE; i++)
	{
		if (numbers[i] != control[i])
		{
			LOG("number[" << i << "]: " << numbers[i]);
			LOG("control[" << i << "]: " << control[i]);
			errorFlag = true;
			break ;
		}
		else if (numbers[i] != assign[i])
		{
			LOG("number[" << i << "]: " << numbers[i]);
			LOG("assign[" << i << "]: " << assign[i]);
			errorFlag = true;
			break ;
		}
		else if (numbers[i] != cpy[i])
		{
			LOG("number[" << i << "]: " << numbers[i]);
			LOG("cpy[" << i << "]: " << cpy[i]);
			errorFlag = true;
			break ;
		}
	}
	if (!errorFlag)
		LOG("All positions match.\n");

	LOG("> Exception check");
	try {numbers[-2] = 0;}
	catch (std::exception const &e)	{ERROR("Invalid position  [-2]: " << e.what());}
	try {numbers[SIZE] = 0;}
	catch (std::exception const &e)	{ERROR("Invalid position [" << SIZE << "]: " << e.what());}

	LOG("\n> Destructor " << std::setw(44) << std::setfill('>') << "");
	delete [] control;
	
	return ;
}

/**
 * @brief Creates and tests Array<std::string>
 * 
 */
void	tetString(void)
{
	LOG("\n> Testing String " << std::setw(40) << std::setfill('>') << "");
	LOG("> Constructors " << std::setw(42) << std::setfill('>') << "");
	Array<std::string>	strings(3);

	strings[0] = "Humberto";
	strings[1] = "Doisberto";
	strings[2] = "Trêsberto";

	Array<std::string>	cpy = strings;
	Array<std::string>	assign;
	assign = strings;

	LOG("\n> Size check");
	if (strings.size() == cpy.size() && 
		strings.size() == assign.size() && 
		cpy.size() == assign.size())
	{
		LOG("Array<std::strings> strings[" << strings.size() << "]");
		LOG("Array<std::strings> cpy[" << cpy.size() << "]");
		LOG("Array<std::strings> assign[" << assign.size() << "]");
		LOG("");
	}
	else
	{
		LOG("Sizes don't match!");
	}

	LOG("> Position check");
	bool	errorFlag = false;
	for (int i = 0; i < 3; i++)
	{
		if (strings[i] != assign[i])
		{
			LOG("number[" << i << "]: " << strings[i]);
			LOG("assign[" << i << "]: " << assign[i]);
			errorFlag = true;
			break ;
		}
		else if (strings[i] != cpy[i])
		{
			LOG("number[" << i << "]: " << strings[i]);
			LOG("cpy[" << i << "]: " << cpy[i]);
			errorFlag = true;
			break ;
		}
	}
	if (!errorFlag)
		LOG("All positions match.\n");
	
	LOG("> Size check");
	LOG("Array<std::string> strings[" << strings.size() << "]");
	for (unsigned int i = 0; i < strings.size(); i++)
		LOG("strings[" << i << "] -> " << strings[i]);

	LOG("\n> Exception check");
	try {strings[-2] = "Menosdoisberto";}
	catch (std::exception const &e)	{ERROR("Invalid position  [-2]: " << e.what());}
	try {strings[SIZE] = "Sizeberto";}
	catch (std::exception const &e)	{ERROR("Invalid position [" << SIZE << "]: " << e.what());}
	
	LOG("\n> Destructor " << std::setw(44) << std::setfill('>') << "");
	return ;
}

int	main(void)
{
	testInt();
	tetString();
	return (0);
}