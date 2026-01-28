/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:15:28 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/28 20:08:50 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*	initialize default constructor fields to empty strings
	- making it clear that the object starts empty
*/

Contact::Contact() 
	: firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}

Contact::Contact(const std::string& firstName,
				 const std::string& lastName,
				 const std::string& nickname,
				 const std::string& phoneNumber,
				 const std::string& darkestSecret)
				: firstName(firstName),
				  lastName(lastName),
				  nickname(nickname),
				  phoneNumber(phoneNumber),
				  darkestSecret(darkestSecret) {}

Contact::~Contact() {}

const std::string& Contact::getFirstName() const
{
	return firstName;
}

const std::string& Contact::getLastName() const
{
	return lastName;
}

const std::string& Contact::getNickname() const
{
	return nickname;
}

const std::string& Contact::getPhoneNumber() const
{
	return phoneNumber;
}

const std::string& Contact::getDarkestSecret() const
{
	return darkestSecret;
}

void Contact::setFirstName(const std::string& newFirstName)
{
	firstName = newFirstName;
}

void Contact::setLastName(const std::string& newLastName)
{
	lastName = newLastName;
}

void Contact::setNickname(const std::string& newNickname)
{
	nickname = newNickname;
}

void Contact::setPhoneNumber(const std::string& newPhoneNumber)
{
	phoneNumber = newPhoneNumber;
}

void Contact::setDarkestSecret(const std::string& newDarkestSecret)
{
	darkestSecret = newDarkestSecret;
}
