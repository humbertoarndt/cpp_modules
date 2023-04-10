/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:24:31 by harndt            #+#    #+#             */
/*   Updated: 2023/04/10 18:47:26 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>		// std::setw
# include <iostream>	// std::cout, std::cin, std::endl
# include <string>		// std::getline, std::string
# include <sstream>
# include "Contact.hpp"

# define ADD "ADD"
# define EMPTY ""
# define EXIT "EXIT"
# define SEARCH "SEARCH"
# define SIZE 8

class PhoneBook
{
	private:
		Contact	_contacts[SIZE];
		unsigned int	_index;
		
		std::string	_get_input(std::string const field);
		void		_set_contact(Contact contact);
		void		_display_phonebook_header(void);
		void		_display_contacts(int i) const;
		void		_display_phonebook_footer(void);
		void		_display_contact_value(std::string value) const;
		void		_print_n_times(char c, int n);
		int			ft_stoi(std::string str);

	
	public:
		PhoneBook(void);
		~PhoneBook(void);
		
		void	prompt_add(void);
		void	prompt_search(void);
};

#endif