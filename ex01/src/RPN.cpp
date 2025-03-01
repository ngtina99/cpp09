/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:32:12 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/03/01 18:23:52 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

RPN::RPN() {
}

bool RPN::expressionParser(const std::string &arg) {
    for (size_t i = 0; i < arg.size(); i++) {
        if (!std::isdigit(arg[i]) && arg[i] != ' ' && arg[i] != '+' && arg[i] != '-' && arg[i] != '*' && arg[i] != '/') {
            return (false);  // Invalid character found
        }
    }
    return (true);  // The string is a valid RPN expression
}

RPN::RPN(const std::string &arg) {
	
	if (!expressionParser(arg))
		throw();
	ss = arg;
	
}

RPN::~RPN() {
}

RPN::RPN(RPN const &copy) {
}

RPN& RPN::operator=(RPN const &rhs) {
}


const char* RPN::parserException::what() const throw() {
	return(MYRED "Error: the expression contains invalid characters" MYEOF);
}

