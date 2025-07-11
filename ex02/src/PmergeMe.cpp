/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:29:51 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/07/12 00:13:37 by ngtina1999       ###   ########.fr       */
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