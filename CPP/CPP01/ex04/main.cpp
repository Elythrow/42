/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazin <gbazin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:24:58 by gbazin            #+#    #+#             */
/*   Updated: 2026/01/07 21:51:32 by gbazin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

std::string	replaceAll(const std::string &content, const sed &data)
{
	if (data.s1.empty())
		return content;
		
	std::string	result;
	size_t		pos = 0;
	size_t		found;

	while ((found = content.find(data.s1, pos)) != std::string::npos)
	{
		result += content.substr(pos, found - pos);
		result += data.s2;
		pos = found + data.s1.length();
	}
	result += content.substr(pos);
	return result;
}

int	processFile(sed &data)
{
	std::ifstream	inputFile(data.filename.c_str());

	if (!inputFile.is_open())
	{
		std::cerr << "Error: cannot open file '" << data.filename << "'" << std::endl;
		return 1;
	}

	std::string	content;
	std::string	line;
	bool		firstLine = true;

	while (std::getline(inputFile, line))
	{
		if (!firstLine)
			content += "\n";
		content += line;
		firstLine = false;
	}
	if (!content.empty())
	{
		inputFile.clear();
		inputFile.seekg(-1, std::ios::end);
		char lastChar;
		inputFile.get(lastChar);
		if (lastChar == '\n')
			content += "\n";
	}
	inputFile.close();

	std::string		newContent = replaceAll(content, data);
	std::string		outputFilename = data.filename + ".replace";
	std::ofstream	outputFile(outputFilename.c_str());
	
	if (!outputFile.is_open())
	{
		std::cerr << "Error: cannot create file '" << outputFilename << "'" << std::endl;
		return 1;
	}
	outputFile << newContent;
	outputFile.close();
	return 0;
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: ./sed <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	sed	data;
	
	data.filename = av[1];
	data.s1 = av[2];
	data.s2 = av[3];
	return processFile(data);
}
