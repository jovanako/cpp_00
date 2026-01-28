/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 18:32:39 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/28 22:31:20 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() {};

PhoneBook::~PhoneBook() {};

void PhoneBook::addContact()
{
	std::string firstName;
	
	while (firstName.empty())
	{
		std::cout << "First name: ";
		std::getline(std::cin, firstName);
		if (firstName.empty())
			std::cout << "First name cannot be empty. Please try again.\n";
	}

	std::string lastName;
	
	while (lastName.empty())
	{
		std::cout << "Last name: ";
		std::getline(std::cin, lastName);
		if (lastName.empty())
			std::cout << "Last name cannot be empty. Please try again.\n";
	}

	std::string nickname;

	while (nickname.empty())
	{
		std::cout << "Nickname: ";
		std::getline(std::cin, nickname);
		if (nickname.empty())
			std::cout << "Nickname cannot be empty. Please try again.\n";
	}

	std::string phoneNumber;

	while (phoneNumber.empty())
	{
		std::cout << "Phone number: ";
		std::getline(std::cin, phoneNumber);
		if (phoneNumber.empty())
			std::cout << "Phone number cannot be empty. Please try again.\n";
	}

	std::string darkestSecret;

	while (darkestSecret.empty())
	{
		std::cout << "Darkest secret: ";
		std::getline(std::cin, darkestSecret);
		if (darkestSecret.empty())
			std::cout << "Darkest secret cannot be empty. Please try again.\n";
	}

	// save into the contact at nextIndex
	contacts[nextIndex].setFirstName(firstName);
	contacts[nextIndex].setLastName(lastName);
	contacts[nextIndex].setNickname(nickname);
	contacts[nextIndex].setPhoneNumber(phoneNumber);
	contacts[nextIndex].setDarkestSecret(darkestSecret);

	if (contactCount < 8)
		contactCount++;
	
	nextIndex++;
	if (nextIndex == 8)
		nextIndex = 0;
	
	std::cout << "Contact added successfully!\n";
}

std::string PhoneBook::formatField(const std::string& str) const
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void PhoneBook::searchContacts() const
{
	if (contactCount == 0)
	{
		std::cout << "Phonebook is empty.\n";
		return;
	}
	
	for (int i = 0; i < contactCount; i++)
	{
		std::cout << "|"
				  << std::setw(10) << i
				  << "|"
				  << std::setw(10) << formatField(contacts[i].getFirstName())
				  << "|"
				  << std::setw(10) << formatField(contacts[i].getLastName())
				  << "|"
				  << std::setw(10) << formatField(contacts[i].getNickname())
				  << "|\n";
	}

	std::cout << "Enter index: ";

	std::string input;
	std::getline(std::cin, input);

	if (input.length() != 1 || input[0] < '0' || input[0] > '9')
	{
		std::cout << "Invalid index.\n";
		return ;
	}
	
	int index = input[0] - '0';
	if (index < 0 || index >= contactCount)
	{
		std::cout << "Index out of range.\n";
		return ;
	}

	const Contact& c = contacts[index];

	std::cout << "First name: " << c.getFirstName() << "\n";
	std::cout << "Last name: " << c.getLastName() << "\n";
	std::cout << "Nickname: " << c.getNickname() << "\n";
	std::cout << "Phone number: " << c.getPhoneNumber() << "\n";
	std::cout << "Darkest secret: " << c.getDarkestSecret() << "\n";
}