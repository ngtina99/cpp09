/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 01:09:17 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/27 03:29:53 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> //exit
#include <list>

#define MYEOF "\033[0m"
#define MYRED "\033[1;31m"
#define MYBLUE "\033[1;34m"
#define MYGREEN "\033[1;32m"
#define MYPURPLE "\033[1;35m"

class BitcoinExchange {
	
	private:
		
		std::list<std::string> ;
	public:

		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange &copy);
		BitcoinExchange &operator=(BitcoinExchange const &rhs);

		void	fileReader(char *argv);

		class fileException : public std::exception {

			const char *what() const throw();

		};

		class firstLineException : public std::exception {

			const char *what() const throw();

		};
};

#endif
