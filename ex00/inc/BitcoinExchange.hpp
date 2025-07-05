/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 01:09:17 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/07/05 22:46:59 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib> //exit
#include <map>
#include <iomanip>
#include <climits>

#define MYEOF	 "\033[0m"
#define MYRED	 "\033[1;31m"
#define MYBLUE	 "\033[1;34m"
#define MYGREEN	 "\033[1;32m"
#define MYPURPLE "\033[1;35m"

#define FILEPATH "data.csv"

class BitcoinExchange {
	
	private:
		
		std::map<std::string, float> _data;

	public:

		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange &copy);
		BitcoinExchange &operator=(BitcoinExchange const &rhs);

		void	fileReader(char *argv);

		void	checkDate(std::string data);
		void	checkValue(float value);
		void	exchangeValue(std::string const &data, float value);

		class fileException : public std::exception {

			public:

				const char *what() const throw();

		};

		class firstLineException : public std::exception {

			public:

				const char *what() const throw();

		};

		class dataBaseException : public std::exception {
			
			public:

				const char *what() const throw();	

		};

		class dateException : public std::exception {
			
			private:

				std::string _errorMessage;
			
			public:

				dateException(const std::string &date);
				virtual ~dateException() throw();
				const char *what() const throw();	

		};

		class tooHighValueException : public std::exception {
			
			public:

				const char *what() const throw();	

		};

		class negativeNumberException : public std::exception {
			
			public:

				const char *what() const throw();	

		};

		class noLowerException : public std::exception {
			
			public:

				const char *what() const throw();	

		};

};

#endif
