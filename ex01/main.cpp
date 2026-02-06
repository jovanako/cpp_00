/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:18:03 by jkovacev          #+#    #+#             */
/*   Updated: 2026/02/06 20:05:09 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int	main()
{
	PhoneBook	phonebook;
	
	std::string	command;
	
	while (true)
	{
		if (std::cin.eof())
			break;
			
		std::cout << "Enter command: ";
		if (!std::getline(std::cin, command)) {
			if (std::cin.eof())
				std::cout << std::endl;
			break;
		}
		
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContacts();
		else if (std::cin.eof() || command == "EXIT")
			break;
		else
			std::cout << "Invalid command. Please enter ADD, SEARCH or EXIT.\n";
	}
	return 0;
}