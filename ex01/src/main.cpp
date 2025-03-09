/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 01:07:16 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/03/09 13:35:55 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

int		main(int argc, char **argv) {
	
	if (argc != 2) {
		std::cerr << MYRED "Error: the program works with an expression as an argument" MYEOF << std::endl;
		return (1);
	}
	try {
		RPN rpn(argv[1]);
		std::cout << rpn.getExpression() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}

}
