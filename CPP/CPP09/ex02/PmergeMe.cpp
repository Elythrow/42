#include "PmergeMe.hpp"

#include <algorithm>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>

/* ************************************************************************** */
/*                              Static helpers                                */
/* ************************************************************************** */

static const int	INT_MAX_VALUE = 2147483647;

/*
** std::clock() (<ctime>, C++98) returns the processor time used by the
** program; dividing by CLOCKS_PER_SEC gives seconds, so the result is scaled
** to microseconds here.
*/
static double	currentTimeInMicroseconds(void)
{
	return (static_cast<double>(std::clock()) * 1000000.0
		/ static_cast<double>(CLOCKS_PER_SEC));
}

static bool	isDigit(char c)
{
	return (c >= '0' && c <= '9');
}

/* Strictly positive integers (0 included), no sign except an optional '+'. */
static bool	isPositiveInteger(const std::string &token)
{
	std::string::size_type	i = 0;

	if (token.empty())
		return (false);
	if (token[i] == '+')
		++i;
	if (i == token.size())
		return (false);

	unsigned long	value = 0;

	for (; i < token.size(); ++i)
	{
		if (!isDigit(token[i]))
			return (false);

		unsigned long	digit = static_cast<unsigned long>(token[i] - '0');

		if (value > (static_cast<unsigned long>(INT_MAX_VALUE) - digit) / 10UL)
			return (false);
		value = value * 10UL + digit;
	}
	return (true);
}

/* The token has already been validated, so no overflow check is needed. */
static int	toInt(const std::string &token)
{
	std::string::size_type	i = 0;
	long					value = 0;

	if (token[i] == '+')
		++i;
	for (; i < token.size(); ++i)
		value = value * 10 + (token[i] - '0');
	return (static_cast<int>(value));
}

/*
** Insertion order of the pending elements.
**
** pend[k] holds b(k + 2), and merge-insertion inserts the b's by groups
** delimited by the Jacobsthal numbers 1, 3, 5, 11, 21, 43... going down
** inside each group: b3 b2, then b5 b4, then b11 b10 ... b6, and so on.
** That ordering is what keeps every binary search inside a range whose size
** is exactly one less than a power of two, hence the minimal number of
** comparisons.
*/
static void	buildInsertionOrder(std::size_t pendSize,
		std::vector<std::size_t> &order)
{
	std::size_t	previous = 1;
	std::size_t	current = 3;

	order.clear();
	while (previous < pendSize + 1)
	{
		std::size_t	limit = current;

		if (limit > pendSize + 1)
			limit = pendSize + 1;
		for (std::size_t k = limit; k > previous; --k)
			order.push_back(k - 2);

		std::size_t	next = current + 2 * previous;

		previous = current;
		current = next;
	}
}

/* Same thing for the std::deque implementation, which stays deque only. */
static void	buildInsertionOrder(std::size_t pendSize,
		std::deque<std::size_t> &order)
{
	std::size_t	previous = 1;
	std::size_t	current = 3;

	order.clear();
	while (previous < pendSize + 1)
	{
		std::size_t	limit = current;

		if (limit > pendSize + 1)
			limit = pendSize + 1;
		for (std::size_t k = limit; k > previous; --k)
			order.push_back(k - 2);

		std::size_t	next = current + 2 * previous;

		previous = current;
		current = next;
	}
}

/*
** A "block" is a run of blockSize integers whose last integer is the biggest
** one of the run; blocks are therefore compared on that last integer.
*/
class VectorBlockLess
{
public:
	explicit VectorBlockLess(std::size_t blockSize) : _blockSize(blockSize)
	{
	}

	bool	operator()(const std::vector<int>::iterator &lhs,
			const std::vector<int>::iterator &rhs) const
	{
		return (*(lhs + _blockSize - 1) < *(rhs + _blockSize - 1));
	}

private:
	std::size_t	_blockSize;
};

class DequeBlockLess
{
public:
	explicit DequeBlockLess(std::size_t blockSize) : _blockSize(blockSize)
	{
	}

	bool	operator()(const std::deque<int>::iterator &lhs,
			const std::deque<int>::iterator &rhs) const
	{
		return (*(lhs + _blockSize - 1) < *(rhs + _blockSize - 1));
	}

private:
	std::size_t	_blockSize;
};

/* ************************************************************************** */
/*                          Orthodox canonical form                           */
/* ************************************************************************** */

PmergeMe::PmergeMe() :
	_tokens(),
	_vector(),
	_deque(),
	_vectorTime(0.0),
	_dequeTime(0.0)
{
}

PmergeMe::PmergeMe(const PmergeMe &other) :
	_tokens(other._tokens),
	_vector(other._vector),
	_deque(other._deque),
	_vectorTime(other._vectorTime),
	_dequeTime(other._dequeTime)
{
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_tokens = other._tokens;
		_vector = other._vector;
		_deque = other._deque;
		_vectorTime = other._vectorTime;
		_dequeTime = other._dequeTime;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

/* ************************************************************************** */
/*                     Ford-Johnson sort: std::vector                         */
/* ************************************************************************** */

void	PmergeMe::_mergeInsertVector(std::vector<int> &container,
		std::size_t blockSize)
{
	typedef std::vector<int>::iterator	Iterator;

	std::size_t	blocks = container.size() / blockSize;

	if (blocks < 2)
		return ;

	bool		hasStraggler = (blocks % 2 != 0);
	std::size_t	paired = blocks - (hasStraggler ? 1 : 0);

	/* 1. inside each pair, move the block holding the bigger value second. */
	for (std::size_t i = 0; i < paired; i += 2)
	{
		Iterator	first = container.begin() + i * blockSize;
		Iterator	second = first + blockSize;

		if (*(first + blockSize - 1) > *(second + blockSize - 1))
			std::swap_ranges(first, second, second);
	}

	/* 2. sort the pairs on their bigger value, recursively. */
	_mergeInsertVector(container, blockSize * 2);

	/*
	** 3. main chain = b1 a1 a2 ... an (already sorted), pending = b2 ... bn
	**    plus the straggler when the number of blocks is odd. Only iterators
	**    on the first integer of each block are moved around, never the
	**    integers themselves.
	*/
	std::vector<Iterator>	mainChain;
	std::vector<Iterator>	pend;
	std::vector<Iterator>	partner;
	std::size_t				pairs = paired / 2;

	mainChain.push_back(container.begin());
	mainChain.push_back(container.begin() + blockSize);
	for (std::size_t i = 1; i < pairs; ++i)
	{
		pend.push_back(container.begin() + (2 * i) * blockSize);
		partner.push_back(container.begin() + (2 * i + 1) * blockSize);
		mainChain.push_back(container.begin() + (2 * i + 1) * blockSize);
	}
	if (hasStraggler)
	{
		pend.push_back(container.begin() + (blocks - 1) * blockSize);
		partner.push_back(container.end());
	}

	/*
	** 4. binary insertion of the pending elements. bk is always smaller than
	**    its own ak, so the search stops right before ak instead of scanning
	**    the whole chain.
	*/
	std::vector<std::size_t>	order;

	buildInsertionOrder(pend.size(), order);

	VectorBlockLess	less(blockSize);

	for (std::size_t i = 0; i < order.size(); ++i)
	{
		std::size_t	index = order[i];
		std::size_t	bound = mainChain.size();

		/*
		** Where does the pair of that pending element sit right now? It
		** started at index + 2 and each of the i insertions already done
		** pushed it right by at most one slot, so walking back from
		** index + 2 + i finds it in a couple of steps instead of scanning
		** the whole chain. The straggler has no pair: it is searched for
		** in the whole chain.
		*/
		if (partner[index] != container.end())
		{
			bound = index + 2 + i;
			if (bound >= mainChain.size())
				bound = mainChain.size() - 1;
			while (bound > 0 && mainChain[bound] != partner[index])
				--bound;
		}

		std::vector<Iterator>::iterator	position = std::upper_bound(
				mainChain.begin(), mainChain.begin() + bound, pend[index],
				less);

		mainChain.insert(position, pend[index]);
	}

	/* 5. flatten the chain back into the container. */
	std::vector<int>	sorted;

	sorted.reserve(blocks * blockSize);
	for (std::size_t i = 0; i < mainChain.size(); ++i)
		sorted.insert(sorted.end(), mainChain[i], mainChain[i] + blockSize);
	std::copy(sorted.begin(), sorted.end(), container.begin());
}

/* ************************************************************************** */
/*                      Ford-Johnson sort: std::deque                         */
/* ************************************************************************** */

void	PmergeMe::_mergeInsertDeque(std::deque<int> &container,
		std::size_t blockSize)
{
	typedef std::deque<int>::iterator	Iterator;

	std::size_t	blocks = container.size() / blockSize;

	if (blocks < 2)
		return ;

	bool		hasStraggler = (blocks % 2 != 0);
	std::size_t	paired = blocks - (hasStraggler ? 1 : 0);

	/* 1. inside each pair, move the block holding the bigger value second. */
	for (std::size_t i = 0; i < paired; i += 2)
	{
		Iterator	first = container.begin() + i * blockSize;
		Iterator	second = first + blockSize;

		if (*(first + blockSize - 1) > *(second + blockSize - 1))
			std::swap_ranges(first, second, second);
	}

	/* 2. sort the pairs on their bigger value, recursively. */
	_mergeInsertDeque(container, blockSize * 2);

	/* 3. main chain = b1 a1 a2 ... an, pending = b2 ... bn (+ straggler). */
	std::deque<Iterator>	mainChain;
	std::deque<Iterator>	pend;
	std::deque<Iterator>	partner;
	std::size_t				pairs = paired / 2;

	mainChain.push_back(container.begin());
	mainChain.push_back(container.begin() + blockSize);
	for (std::size_t i = 1; i < pairs; ++i)
	{
		pend.push_back(container.begin() + (2 * i) * blockSize);
		partner.push_back(container.begin() + (2 * i + 1) * blockSize);
		mainChain.push_back(container.begin() + (2 * i + 1) * blockSize);
	}
	if (hasStraggler)
	{
		pend.push_back(container.begin() + (blocks - 1) * blockSize);
		partner.push_back(container.end());
	}

	/* 4. binary insertion of the pending elements, bounded by their pair. */
	std::deque<std::size_t>	order;

	buildInsertionOrder(pend.size(), order);

	DequeBlockLess	less(blockSize);

	for (std::size_t i = 0; i < order.size(); ++i)
	{
		std::size_t	index = order[i];
		std::size_t	bound = mainChain.size();

		/* Same shortcut as in the std::vector version. */
		if (partner[index] != container.end())
		{
			bound = index + 2 + i;
			if (bound >= mainChain.size())
				bound = mainChain.size() - 1;
			while (bound > 0 && mainChain[bound] != partner[index])
				--bound;
		}

		std::deque<Iterator>::iterator	position = std::upper_bound(
				mainChain.begin(), mainChain.begin() + bound, pend[index],
				less);

		mainChain.insert(position, pend[index]);
	}

	/* 5. flatten the chain back into the container. */
	std::deque<int>	sorted;

	for (std::size_t i = 0; i < mainChain.size(); ++i)
		sorted.insert(sorted.end(), mainChain[i], mainChain[i] + blockSize);
	std::copy(sorted.begin(), sorted.end(), container.begin());
}

/* ************************************************************************** */
/*                             Input and output                               */
/* ************************************************************************** */

void	PmergeMe::_parse(int argc, char **argv)
{
	_tokens.clear();
	for (int i = 1; i < argc; ++i)
	{
		std::istringstream	stream(argv[i]);
		std::string			token;
		bool				empty = true;

		while (stream >> token)
		{
			if (!isPositiveInteger(token))
				throw std::runtime_error("Error");
			_tokens.push_back(token);
			empty = false;
		}
		if (empty)
			throw std::runtime_error("Error");
	}
	if (_tokens.empty())
		throw std::runtime_error("Error");
}

void	PmergeMe::_runVector(void)
{
	double	start = currentTimeInMicroseconds();

	_vector.clear();
	_vector.reserve(_tokens.size());
	for (std::size_t i = 0; i < _tokens.size(); ++i)
		_vector.push_back(toInt(_tokens[i]));
	_mergeInsertVector(_vector, 1);
	_vectorTime = currentTimeInMicroseconds() - start;
}

void	PmergeMe::_runDeque(void)
{
	double	start = currentTimeInMicroseconds();

	_deque.clear();
	for (std::size_t i = 0; i < _tokens.size(); ++i)
		_deque.push_back(toInt(_tokens[i]));
	_mergeInsertDeque(_deque, 1);
	_dequeTime = currentTimeInMicroseconds() - start;
}

void	PmergeMe::_printBefore(void) const
{
	std::cout << "Before:";
	for (std::size_t i = 0; i < _tokens.size(); ++i)
		std::cout << " " << _tokens[i];
	std::cout << std::endl;
}

void	PmergeMe::_printAfter(void) const
{
	std::cout << "After: ";
	for (std::size_t i = 0; i < _vector.size(); ++i)
		std::cout << " " << _vector[i];
	std::cout << std::endl;
}

void	PmergeMe::run(int argc, char **argv)
{
	_parse(argc, argv);
	_printBefore();
	_runVector();
	_runDeque();
	_printAfter();

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _vector.size()
		<< " elements with std::vector<int> : " << _vectorTime << " us"
		<< std::endl;
	std::cout << "Time to process a range of " << _deque.size()
		<< " elements with std::deque<int>  : " << _dequeTime << " us"
		<< std::endl;
}
