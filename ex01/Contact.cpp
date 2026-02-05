/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:15:28 by jkovacev          #+#    #+#             */
/*   Updated: 2026/02/05 19:13:23 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*	initialize default constructor fields to empty strings
	- making it clear that the object starts empty
*/

Contact::Contact() 
	: _firstName(""), _lastName(""), _nickname(""), _phoneNumber(""), _darkestSecret("") {}

Contact::Contact(const std::string& firstName,
				 const std::string& lastName,
				 const std::string& nickname,
				 const std::string& phoneNumber,
				 const std::string& darkestSecret)
				: _firstName(firstName),
				  _lastName(lastName),
				  _nickname(nickname),
				  _phoneNumber(phoneNumber),
				  _darkestSecret(darkestSecret) {}

Contact::~Contact() {}

const	std::string& Contact::getFirstName() const
{
	return _firstName;
}

const	std::string& Contact::getLastName() const
{
	return _lastName;
}

const	std::string& Contact::getNickname() const
{
	return _nickname;
}

const	std::string& Contact::getPhoneNumber() const
{
	return _phoneNumber;
}

const	std::string& Contact::getDarkestSecret() const
{
	return _darkestSecret;
}

void	Contact::setFirstName(const std::string& newFirstName)
{
	_firstName = newFirstName;
}

void	Contact::setLastName(const std::string& newLastName)
{
	_lastName = newLastName;
}

void	Contact::setNickname(const std::string& newNickname)
{
	_nickname = newNickname;
}

void	Contact::setPhoneNumber(const std::string& newPhoneNumber)
{
	_phoneNumber = newPhoneNumber;
}

void	Contact::setDarkestSecret(const std::string& newDarkestSecret)
{
	_darkestSecret = newDarkestSecret;
}
