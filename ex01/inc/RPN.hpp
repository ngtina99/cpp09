/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:09:11 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/03/09 19:10:17 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#define MYEOF		"\033[0m"
#define MYRED		"\033[1;31m"
#define MYBLUE		"\033[1;34m"
#define MYGREEN		"\033[1;32m"
#define MYPURPLE	"\033[1;35m"

#include <iostream>
#include <stack>
#include <cstdlib>
#include <sstream>
#include <exception>

class RPN {

	private:

		std::stack<double> _stack;

	public:

		RPN();
		RPN(const std::string &arg);
		~RPN();
		RPN(RPN const &copy);
		RPN &operator=(RPN const &rhs);

		void	calculateValue(char op);

		class parserException : public std::exception {
			
			const char* what() const throw();
			
		};	
		
		class zeroDivisionException : public std::exception {
			
			const char* what() const throw();
			
		};

		class calculationException : public std::exception {
			
			const char* what() const throw();
			
		};
};

#endif
