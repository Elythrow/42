#include "BitcoinExchange.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

/* ************************************************************************** */
/*                              Static helpers                                */
/* ************************************************************************** */

static bool	isDigit(char c)
{
	return (c >= '0' && c <= '9');
}

static std::string	trim(const std::string &s)
{
	const std::string	spaces = " \t\v\f\r\n";
	std::string::size_type	first = s.find_first_not_of(spaces);

	if (first == std::string::npos)
		return ("");
	std::string::size_type	last = s.find_last_not_of(spaces);
	return (s.substr(first, last - first + 1));
}

static int	toInt(const std::string &s, std::string::size_type pos,
		std::string::size_type len)
{
	int	value = 0;

	for (std::string::size_type i = pos; i < pos + len; ++i)
		value = value * 10 + (s[i] - '0');
	return (value);
}

static bool	isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

static int	daysInMonth(int year, int month)
{
	static const int	days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31,
			30, 31};

	if (month == 2 && isLeapYear(year))
		return (29);
	return (days[month - 1]);
}

/* Accepts strictly "YYYY-MM-DD" and checks that the date really exists. */
static bool	isValidDate(const std::string &date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	for (std::string::size_type i = 0; i < date.size(); ++i)
	{
		if (i == 4 || i == 7)
			continue ;
		if (!isDigit(date[i]))
			return (false);
	}

	int	year = toInt(date, 0, 4);
	int	month = toInt(date, 5, 2);
	int	day = toInt(date, 8, 2);

	if (year < 1 || month < 1 || month > 12)
		return (false);
	if (day < 1 || day > daysInMonth(year, month))
		return (false);
	return (true);
}

/*
** Accepts an optional sign, digits and at most one dot (no exponent, no
** thousands separator). When the literal is well formed but too big for a
** double, we still return true with a huge value so that the caller reports
** "too large a number" instead of "bad input".
*/
static bool	parseNumber(const std::string &token, double &out)
{
	if (token.empty())
		return (false);

	std::string::size_type	i = 0;
	bool					negative = false;

	if (token[i] == '+' || token[i] == '-')
	{
		negative = (token[i] == '-');
		++i;
	}

	int	digits = 0;
	int	dots = 0;

	for (; i < token.size(); ++i)
	{
		if (isDigit(token[i]))
			++digits;
		else if (token[i] == '.')
		{
			if (++dots > 1)
				return (false);
		}
		else
			return (false);
	}
	if (digits == 0)
		return (false);

	std::istringstream	stream(token);

	stream >> out;
	if (stream.fail())
		out = negative ? -1e30 : 1e30;
	return (true);
}

/* ************************************************************************** */
/*                          Orthodox canonical form                           */
/* ************************************************************************** */

BitcoinExchange::BitcoinExchange() : _rates()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
	: _rates(other._rates)
{
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_rates = other._rates;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

/* ************************************************************************** */
/*                                 Database                                   */
/* ************************************************************************** */

void	BitcoinExchange::loadDatabase(const std::string &path)
{
	std::ifstream	file(path.c_str());

	if (!file.is_open())
		throw std::runtime_error("Error: could not open database file: " + path);

	std::string	line;

	_rates.clear();
	while (std::getline(file, line))
	{
		line = trim(line);
		if (line.empty())
			continue ;

		std::string::size_type	comma = line.find(',');
		if (comma == std::string::npos)
			continue ;

		std::string	date = trim(line.substr(0, comma));
		std::string	rate = trim(line.substr(comma + 1));
		double		value = 0.0;

		if (!isValidDate(date) || !parseNumber(rate, value))
			continue ;
		_rates[date] = value;
	}
	if (file.bad())
	{
		file.close();
		throw std::runtime_error("Error: could not open database file: " + path);
	}
	file.close();
	if (_rates.empty())
		throw std::runtime_error("Error: database is empty or malformed: " + path);
}

double	BitcoinExchange::_rateAt(const std::string &date, bool &found) const
{
	std::map<std::string, double>::const_iterator	it;

	found = true;
	it = _rates.lower_bound(date);
	if (it != _rates.end() && it->first == date)
		return (it->second);
	if (it == _rates.begin())
	{
		found = false;
		return (0.0);
	}
	--it;
	return (it->second);
}

/* ************************************************************************** */
/*                                  Input                                     */
/* ************************************************************************** */

void	BitcoinExchange::_evaluateLine(const std::string &line) const
{
	std::string::size_type	bar = line.find('|');

	if (bar == std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return ;
	}

	std::string	date = trim(line.substr(0, bar));
	std::string	token = trim(line.substr(bar + 1));
	double		value = 0.0;

	if (!isValidDate(date))
	{
		std::cout << "Error: bad input => " << (date.empty() ? line : date)
			<< std::endl;
		return ;
	}
	if (!parseNumber(token, value))
	{
		std::cout << "Error: bad input => " << (token.empty() ? line : token)
			<< std::endl;
		return ;
	}
	if (value < 0.0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return ;
	}
	if (value > 1000.0)
	{
		std::cout << "Error: too large a number." << std::endl;
		return ;
	}

	bool	found = false;
	double	rate = _rateAt(date, found);

	if (!found)
	{
		std::cout << "Error: no data before this date => " << date << std::endl;
		return ;
	}
	std::cout << date << " => " << value << " = " << value * rate << std::endl;
}

void	BitcoinExchange::processInput(const std::string &path) const
{
	std::ifstream	file(path.c_str());

	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::string	line;
	bool		first = true;

	while (std::getline(file, line))
	{
		line = trim(line);
		if (first)
		{
			first = false;
			std::string::size_type	bar = line.find('|');
			if (bar != std::string::npos
				&& trim(line.substr(0, bar)) == "date"
				&& trim(line.substr(bar + 1)) == "value")
				continue ;
		}
		if (line.empty())
			continue ;
		_evaluateLine(line);
	}
	if (file.bad())
	{
		file.close();
		throw std::runtime_error("Error: could not open file.");
	}
	file.close();
}
