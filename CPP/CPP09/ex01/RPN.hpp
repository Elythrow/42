#ifndef RPN_HPP
# define RPN_HPP

# include <list>
# include <stack>
# include <string>

/*
** Container choice: std::stack
**
** Evaluating a postfix expression is the textbook LIFO job: every token is
** either pushed, or consumes the two most recently pushed values. std::stack
** exposes exactly push/top/pop and nothing else, so the container itself
** enforces that no element is ever accessed out of order.
**
** std::stack is a container adaptor: by default it is built on std::deque.
** It is instantiated here on std::list so that neither std::deque nor
** std::vector (the two containers used in ex02) appear in this exercise,
** and no container of ex00 (std::map) is used either.
*/

class RPN
{
public:
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	double	evaluate(const std::string &expression);

private:
	std::stack<double, std::list<double> >	_stack;

	void	_push(double value);
	void	_applyOperator(char op);
	void	_clear();
};

#endif
