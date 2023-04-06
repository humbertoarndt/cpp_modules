/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:24:27 by harndt            #+#    #+#             */
/*   Updated: 2023/04/06 17:27:27 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// =============================================================================
// CONSTRUCTOR AND DESTRUCTOR
// =============================================================================

/**
 * @brief Construct a new PhoneBook::PhoneBook object
 * 
 */
PhoneBook::PhoneBook(void): _contacts(), _index()
{
	return ;
}

/**
 * @brief Destroy the PhoneBook::PhoneBook object
 * 
 */
PhoneBook::~PhoneBook(void)
{
	return ;
}

// =============================================================================
// PRIVATE FUNCTIONS
// =============================================================================

/**
 * @brief Gets an user input.
 * 
 * @param field The required field.
 * @return std::string The user input.
 */
std::string	PhoneBook::_get_input(std::string const field)
{
	std::string	input;

	std::cout	<< "Please enter " << field << ":" << std::endl << "> ";
	if (!std::getline(std::cin, input))
		std::cout << "Please entry a value." << std::endl << "> ";
	return (input);
}

/**
 * @brief Stores a contact object into the _contacts array.
 * 
 * @param contact The contact to be stored.
 */
void	PhoneBook::_set_contact(Contact contact)
{
	if (_index == SIZE)
		_index = 1;
	else
		_index++;
	_contacts[_index - 1] = contact;
}

/**
 * @brief Displays phonebook's header.
 */
void	PhoneBook::_display_phonebook_header(void)
{
	_print_n_times('-', 45);
	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First Name";
	std::cout << "|" << std::setw(10) << "Last Name";
	std::cout << "|" << std::setw(10) << "Nickname";
	std::cout << "|" << std::endl;
	_print_n_times('-', 45);
}

void	PhoneBook::_display_contact_value(std::string value) const
{
	if (value.length() > 10)
	{
		value.resize(9);
		value += ".";
	}
	std::cout << std::setw(10) << value << "|";
}

/**
 * @brief Displays all contacts in the phonebook.
 * 
 * @param i An index.
 */
void	PhoneBook::_display_contacts(int i) const
{
	std::cout << "|" << std::setw(10) << i + 1 << "|";
	_display_contact_value(this->_contacts[i].get_first_name());
	_display_contact_value(this->_contacts[i].get_last_name());
	_display_contact_value(this->_contacts[i].get_nickname());
	std::cout << std::endl;
}

/**
 * @brief Displays phonebook's footer.
 * 
 */
void	PhoneBook::_display_phonebook_footer(void)
{
	_print_n_times('-', 45);
	std::cout << std::endl;
}

void	PhoneBook::_print_n_times(char c, int n)
{
	std::cout << std::string(n, c) << std::endl;
}

// =============================================================================
// PUBLIC FUNCTIONS
// =============================================================================

/**
 * @brief Displays the prompt to add a new contact.
 */
void	PhoneBook::prompt_add(void)
{
	Contact contact;
	
	contact.set_first_name(_get_input("First Name"));
	contact.set_last_name(_get_input("Last Name"));
	contact.set_nickname(_get_input("Nickname"));
	contact.set_phone_number(_get_input("Phone Number"));
	contact.set_darkest_secret(_get_input("Darkest Secret"));
	_set_contact(contact);
}

/**
 * @brief Displays the prompt to search a contact in the phonebook.
 * 
 */
void	PhoneBook::prompt_search(void)
{
	std::string	input;

	if (!_index)
	{
		std::cout << "Error: No contacts to display. ADD a contact first" << std::endl;
		return ;
	}
	_display_phonebook_header();
	for (int i = 0; i <= 7; i++)
	{
		_display_contacts(i);
		_display_phonebook_footer();
	}
	input = _get_input("an index to select a contact");
	if (ft_stoi(input) > 0 && ft_stoi(input) < 9)
		_contacts[ft_stoi(input) - 1].display();
	else
		return ;
}
