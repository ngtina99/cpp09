/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:29:54 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/03/16 23:19:27 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#define MYEOF		"\033[0m"
#define MYRED		"\033[1;31m"
#define MYBLUE		"\033[1;34m"
#define MYGREEN		"\033[1;32m"
#define MYPURPLE	"\033[1;35m"

#include <exception>

class PmergeMe {

	public:

		PmergeMe();
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& other);
		PmergeMe(const PmergeMe& other);

	private:

		
		

}


#endif
