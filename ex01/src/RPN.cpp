/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:32:12 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/03/09 18:10:46 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

RPN::RPN() {
}

// Extra operators (3 + +).
// Too many numbers (3 4 5 +).
// Division by zero (3 0 /).

RPN::RPN(const std::string &arg) {
	
	std::string inputValue;
	std::stringstream ss(arg);
	for (size_t i = 0; i < arg.length(); i++) {
		
		getline(ss, inputValue, ' ');		
		if((inputValue.length() == 1 && isdigit(inputValue[0])) || (inputValue.length() == 2 && (inputValue[0] == '-' || inputValue[0] == '-') && isdigit(inputValue[1])))
			std::cout << arg << std::endl;
		else
			throw(parserException());
	}	
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

