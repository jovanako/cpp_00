/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 18:32:39 by jkovacev          #+#    #+#             */
/*   Updated: 2026/02/06 21:59:31 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cctype>

PhoneBook::PhoneBook() : _contactCount(0), _nextIndex(0) {};

PhoneBook::~PhoneBook() {};

void	PhoneBook::addContact()
{
	std::string firstName;
	
	while (firstName.empty())
	{
		std::cout << "First name: ";
		if (!std::getline(std::cin, firstName)) {
			std::cout << std::endl;
			return;
		}
		if (firstName.empty())
			std::cout << "First name cannot be empty. Please try again.\n";
	}

	std::string lastName;
	
	while (lastName.empty())
	{
		std::cout << "Last name: ";
		if (!std::getline(std::cin, lastName)) {
			std::cout << std::endl;
			return;
		}
		if (lastName.empty())
			std::cout << "Last name cannot be empty. Please try again.\n";
	}

	std::string nickname;

	while (nickname.empty())
	{
		std::cout << "Nickname: ";
		if (!std::getline(std::cin, nickname)) {
			std::cout << std::endl;
			return;
		}
		if (nickname.empty())
			std::cout << "Nickname cannot be empty. Please try again.\n";
	}

	std::string phoneNumber;

	while (true)
	{
		std::cout << "Phone number: ";
		
		if (!std::getline(std::cin, phoneNumber)) {
			std::cout << std::endl;
			return;
		}

		if (phoneNumber.empty()) {
			std::cout << "Phone number cannot be empty. Please try again.\n";
			continue;
		}
		
		bool isValid = true;
		std::string::size_type i = 0;
		
		if (phoneNumber[0] == '+') {
			if (phoneNumber.length() == 1)
				isValid = false;
			else
				i = 1;
		}
		
		for (; i < phoneNumber.length(); i++) {
			if (!std::isdigit(static_cast<unsigned char>(phoneNumber[i]))) {
				isValid = false;
				break;
			}
		}
		
		if (isValid)
			break;
		else
			std::cout << "Invalid input. Please use only digits or a leading '+'.\n";
	}

	std::string darkestSecret;

	while (darkestSecret.empty())
	{
		std::cout << "Darkest secret: ";
		if (!std::getline(std::cin, darkestSecret)) {
			std::cout << std::endl;
			return;
		}
		if (darkestSecret.empty())
			std::cout << "Darkest secret cannot be empty. Please try again.\n";
	}

	_contacts[_nextIndex].setFirstName(firstName);
	_contacts[_nextIndex].setLastName(lastName);
	_contacts[_nextIndex].setNickname(nickname);
	_contacts[_nextIndex].setPhoneNumber(phoneNumber);
	_contacts[_nextIndex].setDarkestSecret(darkestSecret);

	if (_contactCount < 8)
		_contactCount++;
	
	_nextIndex++;
	if (_nextIndex == 8)
		_nextIndex = 0;
	
	std::cout << "Contact added successfully!\n";
}

std::string	PhoneBook::formatField(const std::string& str) const
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	PhoneBook::searchContacts() const
{
	if (_contactCount == 0)
	{
		std::cout << "Phonebook is empty.\n";
		return;
	}
	
	for (int i = 0; i < _contactCount; i++)
	{
		std::cout << "|"
				  << std::setw(10) << i
				  << "|"
				  << std::setw(10) << formatField(_contacts[i].getFirstName())
				  << "|"
				  << std::setw(10) << formatField(_contacts[i].getLastName())
				  << "|"
				  << std::setw(10) << formatField(_contacts[i].getNickname())
				  << "|\n";
	}

	std::string input;
	int index;
	while (true) {
		std::cout << "Enter index: ";
	
		if (!std::getline(std::cin, input)) {
				std::cout << std::endl;
				return;
		}

		if (input.length() != 1 || input[0] < '0' || input[0] > '9')
		{
			std::cout << "Invalid index.\n";
			continue;
		}
		
		index = input[0] - '0';
		if (index < 0 || index >= _contactCount)
		{
			std::cout << "Index out of range.\n";
			continue;
		}
		if (index >= 0 && index <= _contactCount)
			break;
	}

	const Contact& c = _contacts[index];

	std::cout << "First name: " << c.getFirstName() << "\n";
	std::cout << "Last name: " << c.getLastName() << "\n";
	std::cout << "Nickname: " << c.getNickname() << "\n";
	std::cout << "Phone number: " << c.getPhoneNumber() << "\n";
	std::cout << "Darkest secret: " << c.getDarkestSecret() << "\n";
}