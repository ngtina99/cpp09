/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:32:12 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/03/09 19:27:21 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

RPN::RPN() {
}

// Extra operators (3 + +).
// Too many numbers (3 4 5 +).
// Division by zero (3 0 /).

void	RPN::calculateValue(char op) {
	
	int a = 0;
	int b = 0;
	int result = 0;

	if(_stack.size() < 2)
		throw(calculationException());

	a = _stack.top();
	_stack.pop();
	b = _stack.top();
	_stack.pop();
	switch (op) {
		case '+':
			result = a + b;
			break;
		case '-':
			result = b - a;
			break;
		case '*':
			result = a * b;
			break;
		case '/':
			if (b == 0)
				throw(zeroDivisionException());
			else
				result = a / b; //TODO
			break;
	}
	_stack.push(result);
}

RPN::RPN(const std::string &arg) {
	
	std::string inputValue;
	std::stringstream ss(arg);
	while (std::getline(ss, inputValue, ' ')) {	
		if((inputValue.length() == 1 && isdigit(inputValue[0])) || (inputValue.length() == 2 && (inputValue[0] == '-' || inputValue[0] == '+') && isdigit(inputValue[1])))
			_stack.push(std::atoi(inputValue.c_str()));
		else if (inputValue[0] == '-' || inputValue[0] == '+' || inputValue[0] == '*' || inputValue[0] == '/')
			calculateValue(inputValue[0]);
		else
			throw(parserException());
	}
	std::cout << _stack.top() << std::endl;
}

RPN::~RPN() {
}

//TODO
RPN::RPN(RPN const &copy) {
	(void)copy;
}

//TODO
RPN& RPN::operator=(RPN const &rhs) {
	(void)rhs;
	return(*this);
}


const char* RPN::parserException::what() const throw() {
	return(MYRED "Error: the expression contains invalid characters" MYEOF);
}

const char* RPN::calculationException::what() const throw() {
	return(MYRED "Error: the expression can't be executed" MYEOF);
}

const char* RPN::zeroDivisionException::what() const throw() {
	return(MYRED "Error: division by zero" MYEOF);
}


