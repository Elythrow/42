/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:18:23 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/05 00:33:27 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

class PhoneBook {
	private :
		Contact	Contacts[8];
		int		NbContacts;
		int		OldestIndex;
		std::string	truncate_str(std::string str) const;
		void		display_contact(int index) const;
		void		display_contacts() const;
	public :
		PhoneBook();
		void add_contact();
		void search_contact();
};

#endif