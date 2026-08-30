#include "RPN.hpp"

#include <sstream>
#include <stdexcept>

/* ************************************************************************** */
/*                              Static helpers                                */
/* ************************************************************************** */

static bool	isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

static bool	isDigit(char c)
{
	return (c >= '0' && c <= '9');
}

/* ************************************************************************** */
/*                          Orthodox canonical form                           */
/* ************************************************************************** */

RPN::RPN() : _stack()
{
}

RPN::RPN(const RPN &other) : _stack(other._stack)
{
}

RPN	&RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return (*this);
}

RPN::~RPN()
{
}

/* ************************************************************************** */
/*                                Evaluation                                  */
/* ************************************************************************** */

void	RPN::_clear()
{
	while (!_stack.empty())
		_stack.pop();
}

void	RPN::_push(double value)
{
	_stack.push(value);
}

void	RPN::_applyOperator(char op)
{
	if (_stack.size() < 2)
		throw std::runtime_error("Error");

	double	right = _stack.top();

	_stack.pop();

	double	left = _stack.top();

	_stack.pop();
	if (op == '+')
		_stack.push(left + right);
	else if (op == '-')
		_stack.push(left - right);
	else if (op == '*')
		_stack.push(left * right);
	else
	{
		if (right == 0.0)
			throw std::runtime_error("Error");
		_stack.push(left / right);
	}
}

/*
** The subject guarantees single digit operands ("less than 10"), so a valid
** token is exactly one character long: a digit or one of "+ - * /".
*/
double	RPN::evaluate(const std::string &expression)
{
	std::istringstream	stream(expression);
	std::string			token;

	_clear();
	while (stream >> token)
	{
		if (token.size() != 1)
			throw std::runtime_error("Error");
		if (isDigit(token[0]))
			_push(static_cast<double>(token[0] - '0'));
		else if (isOperator(token[0]))
			_applyOperator(token[0]);
		else
			throw std::runtime_error("Error");
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error");

	double	result = _stack.top();

	_stack.pop();
	return (result);
}
