/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 01:07:16 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/07/12 01:03:45 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

const char *PmergeMe::wrongInput::what() const throw() {
	// return ("use integer sequence which only containt positive integers with no duplication");
	return ("Error");
}

void	PmergeMe::organizeArg(int argc, char**argv) {
		
	for(int i = 0; i < argc; i++) {
		for (int j = 0; argv[j]; j++) {
			if(!std::isdigit(static_cast<unsigned char>(argv[i][j])))
				throw (wrongInput());
			j++;
		}
		
		int num = std::atoi(argv[i]);
		if (num <= 0)
			throw (wrongInput());
		
		for (int k = 0; k < _vector.size(); k++) {
			if (_vector[k] == num)
				throw (wrongInput());
		}

		_vector.push_back(num);
		_deque.push_back(num);
		
	i++;
	}
	
}

int	main(int argc, char **argv) {

	try {
		PmergeMe pmergeMe;
		pmergeMe.organizeArg(argc, argv);
	}
	catch(const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}

	return (0);
// When inserting the small elements back, use binary search to find the minimal insert position → this keeps the number of comparisons low.
	// int main(int argc, char** argv) {
    // // 1. Parse and validate arguments
    // // 2. Store in vector and deque
    // // 3. Print Before
    // // 4. Time and sort vector
    // // 5. Time and sort deque
    // // 6. Print After and timing
}
