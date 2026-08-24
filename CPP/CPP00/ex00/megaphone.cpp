/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:25:05 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/04 19:42:33 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include <iostream>

 int main(int ac, char **av)
 {
	int		i = 1;
	int		j;
	std::string str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	
	if (ac < 2)
		std::cout << str;
	else
	{
		while (i < ac && av[i])
		{
			str = av[i];
			j = 0;
			while (str[j] != '\0')
			{
				str[j] = std::toupper(str[j]);
				j ++;
			}
			std::cout << str;
			i ++;
		}
	}
	std::cout << "\n";
	return (0);
 }