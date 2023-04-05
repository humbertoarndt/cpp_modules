/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:24:33 by harndt            #+#    #+#             */
/*   Updated: 2023/04/05 18:10:30 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

// =============================================================================
// CONSTRUCTOR AND DESTRUCTOR
// =============================================================================

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

// =============================================================================
// GETTERS
// =============================================================================

/**
 * @brief Set the first name object
 * 
 * @param firstName The string to be set as firstName.
 */
void	Contact::set_first_name(std::string firstName)
{
	this->_firstName = firstName;
}

/**
 * @brief Set the last name object
 * 
 * @param lastName The string to be set as lastName.
 */
void	Contact::set_last_name(std::string lastName)
{
	this->_lastName = lastName;
}

/**
 * @brief Set the nickname object
 * 
 * @param nickname The string to be set as nickname.
 */
void	Contact::set_nickname(std::string nickname)
{
	this->_nickname = nickname;
}

/**
 * @brief Set the phone number object
 * 
 * @param phoneNumber The string to be set as phoneNumber.
 */
void	Contact::set_phone_number(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

/**
 * @brief Set the darkest secret object
 * 
 * @param darkestSecret The string to be set as darkestSecret.
 */
void	Contact::set_darkest_secret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}

// =============================================================================
// SETTERS
// =============================================================================

/**
 * @brief Get the first name object
 * 
 * @return std::string firstName
 */
std::string	Contact::get_first_name(void) const
{
	return (this->_firstName);
}

/**
 * @brief Get the last name object
 * 
 * @return std::string lastName
 */
std::string	Contact::get_last_name(void) const
{
	return (this->_lastName);
}

/**
 * @brief Get the nickname object
 * 
 * @return std::string nickname
 */
std::string	Contact::get_nickname(void) const
{
	return (this->_nickname);
}

/**
 * @brief Get the phone number object
 * 
 * @return std::string phoneNumber
 */
std::string	Contact::get_phone_number(void) const
{
	return (this->_phoneNumber);
}

/**
 * @brief Get the darkest secret object
 * 
 * @return std::string darkestScret
 */
std::string	Contact::get_darkest_secret(void) const
{
	return (this->_darkestSecret);
}

// =============================================================================
// UTILS
// =============================================================================

void	Contact::display(void)
{
	std::cout << "First Name:\t" << this->_firstName << std::endl;
	std::cout << "Last Name:\t" << this->_lastName << std::endl;
	std::cout << "Nickname:\t" << this->_nickname << std::endl;
	std::cout << "Phone Number:\t" << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret:\t" << this->_darkestSecret << std::endl;
}
