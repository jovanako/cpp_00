/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:18:03 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/28 22:51:20 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int main()
{
	PhoneBook phonebook;
	
	std::string command;
	
	while (true)
	{
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
		
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContacts();
		else if (command == "EXIT")	
			break;
		else
			std::cout << "Invalid command. Please enter ADD, SEARCH or EXIT.\n";
	}
	return 0;
}