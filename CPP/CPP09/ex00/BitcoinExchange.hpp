#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

/*
** Container choice: std::map<std::string, double>
**
** - The database is a set of unique keys (dates) mapped to a value (rate),
**   which is exactly what a map models.
** - std::map keeps its keys sorted, so "give me the closest earlier date"
**   is a single O(log n) lower_bound() call instead of a linear scan.
** - Dates are stored as "YYYY-MM-DD" strings: because every field is
**   zero-padded and fixed width, the lexicographical order of the strings
**   is the chronological order, so no custom comparator is needed.
*/

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void	loadDatabase(const std::string &path);
	void	processInput(const std::string &path) const;

private:
	std::map<std::string, double>	_rates;

	double	_rateAt(const std::string &date, bool &found) const;
	void	_evaluateLine(const std::string &line) const;
};

#endif
