/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:18:01 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/05 00:24:37 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {
	private :
		std::string FirstName;
		std::string LastName;
		std::string Nickname;
		std::string PhoneNumber;
		std::string DarkestSecret;
	public :
		Contact();
		std::string get_FirstName() const;
        std::string get_LastName() const;
        std::string get_Nickname() const;
        std::string get_PhoneNumber() const;
        std::string get_DarkestSecret() const;
		void set_contact(std::string FirstName, std::string LastName, std::string Nickname, std::string PhoneNumber, std::string DarkestSecret);
};

#endif