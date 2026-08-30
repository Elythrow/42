#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <cstddef>
# include <deque>
# include <string>
# include <vector>

/*
** Container choice: std::vector<int> and std::deque<int>
**
** Merge-insert (Ford-Johnson) needs two things from its container:
**   - random access, because every pending element is placed with a *binary*
**     search (a std::list would turn each insertion into a linear walk and
**     ruin the whole point of the algorithm);
**   - insertion in the middle of the sequence, which is where the two
**     containers differ and why comparing them is interesting.
**
** std::vector stores one contiguous buffer: iteration is cache friendly and
** it is normally the fastest of the two, but every insertion shifts the tail
** and it reallocates when it grows.
** std::deque stores fixed size chunks plus a map of pointers: it grows
** without moving the existing elements, but each access costs one extra
** indirection, so it is usually slightly slower here.
**
** Neither is used in ex00 (std::map) nor in ex01 (std::stack on std::list).
*/

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void	run(int argc, char **argv);

private:
	std::vector<std::string>	_tokens;
	std::vector<int>			_vector;
	std::deque<int>				_deque;
	double						_vectorTime;
	double						_dequeTime;

	void	_parse(int argc, char **argv);
	void	_runVector(void);
	void	_runDeque(void);
	void	_printBefore(void) const;
	void	_printAfter(void) const;

	/*
	** Ford-Johnson merge-insertion, written once per container as advised by
	** the subject. "blockSize" is the number of integers making up one
	** element at the current recursion level: the recursion pairs elements
	** and calls itself with twice the size instead of building nested
	** containers, so the data never leaves the original container.
	*/
	static void	_mergeInsertVector(std::vector<int> &container,
			std::size_t blockSize);
	static void	_mergeInsertDeque(std::deque<int> &container,
			std::size_t blockSize);
};

#endif
