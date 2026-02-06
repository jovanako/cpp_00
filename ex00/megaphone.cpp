/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:47:28 by jkovacev          #+#    #+#             */
/*   Updated: 2026/02/06 08:56:14 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

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