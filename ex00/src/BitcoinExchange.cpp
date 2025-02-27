/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 01:09:13 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/27 03:27:59 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

BitcoinExchange::BitcoinExchange() {	
}

BitcoinExchange::~BitcoinExchange() {	
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &copy) {
	(void)copy;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const &rhs) {
	(void)rhs;
	return (*this);
}

void	BitcoinExchange::fileReader(char *argv) {

	std::ifstream file;
	file.open(argv);
	if(!file.is_open())
		throw(fileException());
	std::string	line;
	std::getline(file, line);
	if(line.empty())
		throw(fileException());
	if(line != "data | value")
		throw(firstLineException());
	while(getline(file,line)) {
		try {
			checkLine(line);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		
	}
	//if(line != "data | value")
// 		This program must use a database in csv format which will represent bitcoin price
// over time

		// If the date used in the input does not exist in your DB then you
		// must use the closest date contained in your DB. Be careful to use the
		// lower date and not the upper one.
		
}

const char* BitcoinExchange::fileException::what() const throw() {
	return(MYRED "Error: couldn't open the file or it was empty" MYEOF);
}

const char* BitcoinExchange::firstLineException::what() const throw() {
	return(MYRED "Error: first line is not exactly 'data | value'" MYEOF);
}

