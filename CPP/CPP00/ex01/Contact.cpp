/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:18:09 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/05 00:29:04 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}


std::string Contact::get_FirstName() const
{
    return this->FirstName;
}

std::string Contact::get_LastName() const
{
    return this->LastName;
}

std::string Contact::get_Nickname() const
{
    return this->Nickname;
}

std::string Contact::get_PhoneNumber() const
{
    return this->PhoneNumber;
}

std::string Contact::get_DarkestSecret() const
{
    return this->DarkestSecret;
}

void Contact::set_contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
{
    FirstName = fn;
    LastName = ln;
    Nickname = nn;
    PhoneNumber = pn;
    DarkestSecret = ds;
}

