/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:47:28 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/28 18:26:34 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

/*	std::string arg(...);	-> This is object construction
								- 'arg' is a std::string object
								- the parentheses call a constructor
	So this line means:
		"Create a std::string named 'arg' and initialize it using the C-string argv[i]."
*/

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	for (int i = 1; i < argc; i++)
	{
		std::string arg(argv[i]);
		
		for (std::string::size_type j = 0; j < arg.length(); j++)
			arg[j] = std::toupper(arg[j]);
		
		std::cout << arg;
		
		if (i < argc - 1)
			std::cout << " ";
	}
	
	std::cout << std::endl;
	return 0;
}