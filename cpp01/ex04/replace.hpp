/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:42:59 by harndt            #+#    #+#             */
/*   Updated: 2023/04/17 16:28:16 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __REPLACE_H__
#define __REPLACE_H__

# include <iostream>	// std::cout, std::string
# include <fstream>		// std::ifstream, std::ofstream

// =============================================================================
// FUNCTION
// =============================================================================

bool	check_arg_nb(int argc);
bool	search_empty(std::string s1);
bool	check_in_file(std::ifstream &in);
bool	check_out_file(std::ofstream &out);
void	replace(std::ifstream &in, std::ofstream &out, std::string s1, \
				std::string s2);

#endif