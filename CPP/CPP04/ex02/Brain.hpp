/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:51:58 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/09 18:30:14 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(std::string idea);
		Brain(const Brain& other);
		const Brain& operator=(const Brain& other);
		~Brain();
		std::string getIdea(int index) const;
		void setIdea(int index, const std::string& idea);
};

#endif