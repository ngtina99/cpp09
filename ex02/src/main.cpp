/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 01:07:16 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/08/04 03:43:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

int	main(int argc, char **argv) {

	PmergeMe pmergeMe;

	try {
		pmergeMe.organizeVector(argc, argv);
	}
	catch(const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	pmergeMe.sortVector();

	try {
		pmergeMe.organizeDeque(argc, argv);
	}
	catch(const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	pmergeMe.sortDeque();

	pmergeMe.printResult(argv);

	return (0);

}

//	./PmergeMe $(shuf -i 1-100000 -n 3000)
