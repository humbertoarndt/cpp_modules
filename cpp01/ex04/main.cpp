/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:34:01 by harndt            #+#    #+#             */
/*   Updated: 2023/04/17 16:28:38 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int	main(int argc, char *argv[])
{
	// Checks if the number of argument is valid.
	if (!check_arg_nb(argc))
		return (1);

	// Checks if the 'in' file exist or is open
	std::ifstream	in(argv[1]);
	if (!check_in_file(in))
		return (1);

	// Creates ".replace" file
	std::string	filename(argv[1]);
	std::ofstream	out((filename + ".replace").c_str());
	if (!check_out_file(out))
		return (1);

	// Getting the string and checks if s1 is valid
	std::string	s1(argv[2]);
	std::string	s2(argv[3]);
	if (search_empty(s1))
		return (1);

	// Writes on out file, replacing all occurency of s1 for s2
	replace(in, out, s1, s2);
	
	// Closes in/out fds
	in.close();
	out.close();
	return (0);
}
