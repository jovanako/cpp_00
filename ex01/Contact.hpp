/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkovacev <jkovacev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:15:36 by jkovacev          #+#    #+#             */
/*   Updated: 2026/01/28 20:02:28 by jkovacev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

/*	Contact();	->	default constructor is needed because otherwise
					Contact contacts[8]; will fail because it tries 
					to call a constructor with no arguments
	- Getters are marked const, allowing read-only access even from const objects.
	- Setters pass by const reference, which avoids unnecessary string copying.
*/

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		Contact();	// default constructor
		Contact(const std::string& firstName,
				const std::string& lastName,
				const std::string& nickname,
				const std::string& phoneNumber,
				const std::string& darkestSecret);
		~Contact();

		// Getters
		const std::string& getFirstName() const;
		const std::string& getLastName() const;
		const std::string& getNickname() const;
		const std::string& getPhoneNumber() const;
		const std::string& getDarkestSecret() const;

		// Setters
		void setFirstName(const std::string& newFirstName);
		void setLastName(const std::string& newLastName);
		void setNickname(const std::string& newNickname);
		void setPhoneNumber(const std::string& newPhoneNumber);
		void setDarkestSecret(const std::string& newDarkestSecret);
};

#endif