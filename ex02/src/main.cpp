/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 01:07:16 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/07/12 03:26:47 by ngtina1999       ###   ########.fr       */
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
	
	pmergeMe.organizeDeque(argc, argv);
	pmergeMe.sortDeque();

	pmergeMe.printResult(argv);

	return (0);

}

//	./PmergeMe $(shuf -i 1-100000 -n 3000)
