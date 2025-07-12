/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:29:51 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/07/12 14:45:20 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

PmergeMe::~PmergeMe () {
}

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe &other) : _vector(other._vector), _deque(other._deque) {
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other) {
	
	if(this != &other) { // because then it would make a loop if it's pointing to the same address
		_vector = other._vector;
		_deque = other._deque;
	}
	return (*this);

}

const char *PmergeMe::wrongInput::what() const throw() {
	// return ("use integer sequence which only containt positive integers with no duplication");
	return ("Error");
}

void	PmergeMe::organizeVector(int argc, char**argv) {

	clock_t start = clock();

	if (argc < 2)
		throw (wrongInput());

	for(int i = 1; i < argc; i++) {
		for (int j = 0; argv[i][j]; j++) {
			if(!(argv[i][j] >= '0' && argv[i][j] <= '9')){
				std::cout << argv[i][j] << std::endl;
				throw (wrongInput());
			}
		}
		
		int num = std::atoi(argv[i]);
		if (num <= 0) {
			throw (wrongInput());
		}
		
		for (size_t k = 0; k < _vector.size(); k++) {
			if (_vector[k] == num) {
				throw (wrongInput());
			}
		}
		
		_vector.push_back(num);
		
	}

	clock_t end = clock();
 	_vectorTime = double(end - start) / CLOCKS_PER_SEC * 1e6;  // microseconds
}

void PmergeMe::sortVector() {
	
	clock_t start = clock();

	if (_vector.size() == 1)
		return ;
		
	std::vector<int> smaller;
	std::vector<int> bigger;

	for (size_t i = 0; i + 1 < _vector.size(); i += 2) {
		if (_vector[i] < _vector[i + 1]) {
			smaller.push_back(_vector[i]);
			bigger.push_back(_vector[i + 1]);
		}
		else {
			bigger.push_back(_vector[i]);
			smaller.push_back(_vector[i + 1]);
		}
	}

	if (_vector.size() % 2 != 0)
		smaller.push_back(_vector.back());

	std::sort(bigger.begin(), bigger.end());

	for (size_t i = 0; i < smaller.size(); ++i) {
		std::vector<int>::iterator correctPosition = std::lower_bound(bigger.begin(), bigger.end(), smaller[i]);
		bigger.insert(correctPosition, smaller[i]);
	}

	_vector = bigger;

	clock_t end = clock();
 	_vectorTime += double(end - start) / CLOCKS_PER_SEC * 1e6;  // microseconds

}

void	PmergeMe::organizeDeque(int argc, char**argv) {
	
	clock_t start = clock();

	if (argc < 2)
		throw (wrongInput());

	for(int i = 1; i < argc; i++) {
		for (int j = 0; argv[i][j]; j++) {
			if(!(argv[i][j] >= '0' && argv[i][j] <= '9')){
				std::cout << argv[i][j] << std::endl;
				throw (wrongInput());
			}
		}
		
		int num = std::atoi(argv[i]);
		if (num <= 0) {
			throw (wrongInput());
		}
		
		for (size_t k = 0; k < _vector.size(); k++) {
			if (_deque[k] == num) {
				throw (wrongInput());
			}
		}
		
		_deque.push_back(num);
		
	}
	
	clock_t end = clock();
 	_dequeTime = double(end - start) / CLOCKS_PER_SEC * 1e6;  // microseconds

	
}

void PmergeMe::sortDeque() {
	
	clock_t start = clock();

	if (_deque.size() == 1)
		return ;

	std::deque<int> smaller;
	std::deque<int> bigger;

	for (size_t i = 0; i + 1 < _deque.size(); i += 2) {
		if (_deque[i] < _deque[i + 1]) {
			smaller.push_back(_deque[i]);
			bigger.push_back(_deque[i + 1]);
		}
		else {
			bigger.push_back(_deque[i]);
			smaller.push_back(_deque[i + 1]);
		}
	}

	if (_deque.size() % 2 != 0)
		smaller.push_back(_deque.back());

	std::sort(bigger.begin(), bigger.end());

	for (size_t i = 0; i < smaller.size(); ++i) {
		std::deque<int>::iterator correctPosition = std::lower_bound(bigger.begin(), bigger.end(), smaller[i]);
		bigger.insert(correctPosition, smaller[i]);
	}

	_deque = bigger;

	clock_t end = clock();
 	_dequeTime += double(end - start) / CLOCKS_PER_SEC * 1e6;  // microseconds

}

void	PmergeMe::printResult(char **argv) {
	
	std::cout << "Before:	";
	for(size_t i = 0; argv[i]; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl;
	std::cout << "After:	";
	for(size_t i = 0; i < this->_vector.size(); i++)
			std::cout << _vector[i] << " ";
	 std::cout << std::endl;

	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << _vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << _dequeTime << " us" << std::endl;

}
