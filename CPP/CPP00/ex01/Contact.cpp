/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:18:09 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/05 00:21:05 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}


std::string Contact::get_FirstName()
{
    return this->FirstName;
}

std::string Contact::get_LastName()
{
    return this->LastName;
}

std::string Contact::get_Nickname()
{
    return this->Nickname;
}

std::string Contact::get_PhoneNumber()
{
    return this->PhoneNumber;
}

std::string Contact::get_DarkestSecret()
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

