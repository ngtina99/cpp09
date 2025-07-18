/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:29:54 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/07/12 03:16:45 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#define MYEOF		"\033[0m"
#define MYRED		"\033[1;31m"
#define MYBLUE		"\033[1;34m"
#define MYGREEN		"\033[1;32m"
#define MYPURPLE	"\033[1;35m"

#include <iostream>
#include <cstdio>
#include <exception>
#include <deque>
#include <vector>
#include <cstdlib>   // for std::atoi
#include <cctype>    // for std::isdigit
#include <algorithm> //for sort
#include <ctime>


class PmergeMe {

	private:

		std::vector<int> _vector;
		std::deque<int> _deque;
		double	_vectorTime;
		double	_dequeTime;

	public:

		PmergeMe();
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& other);
		PmergeMe(const PmergeMe& other);

		void	organizeVector(int argc, char **argv);
		void	organizeDeque(int argc, char **argv);

		void	sortVector();
		void	sortDeque();

		void	printResult(char **argv);
		
	class wrongInput : public std::exception {
		
		public:
		
			const char *what()	const throw();

	};

};


#endif
