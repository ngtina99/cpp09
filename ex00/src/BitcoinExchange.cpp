/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 01:09:13 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/28 18:19:05 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

BitcoinExchange::BitcoinExchange() {

	std::ifstream	file("../data.csv");
	std::string		line;

	if(!file.is_open())
		throw(dataBaseException());
	std::getline(file, line);
	if(line.empty())
		throw(fileException());
	while(std::getline(file, line)) {

		std::string date, exchangeRateStr;
		float exchangeRate = 0.0;
		
		std::stringstream ss(line);
		std::getline(ss, date, ',');
		std::getline(ss, exchangeRateStr, '\n');

		std::istringstream iss(exchangeRateStr);
		iss >> exchangeRate;

		this->_data[date] =exchangeRate;

	}
	file.close();

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

void	BitcoinExchange::checkDate(std::string data) {

	int	year;
	int	month;
	int	day;
	std::string dashChar;
	std::stringstream ss(data);

	ss >> year >> dashChar >> month >> dashChar >> day;
	if (year < 0 || year > 999999 || month < 1 || month > 12 || day < 1 || day > 31)
		throw(dateException(data));
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30))
		throw(dateException(data));
	else if ((year % 4 == 0 && month == 2 && day !=29) || (year % 4 == 0 && month == 2 && day !=28))
		throw(dateException(data));
}

void	BitcoinExchange::checkValue(float value) {
	if (value > INT_MAX)
		throw(tooHighValueException());
	else if(value < 0)
		throw(negativeNumberException());
}

void	BitcoinExchange::exchangeValue(std::string const &date, float value) {
	
	std::map<std::string, float>::iterator it;
	it = _data.lower_bound(date);
	
	if (it != _data.end() && date == it->first)
		std::cout << date << " => " << value << value * it->second << std::endl;
	if(it != _data.end())
		std::cout << date << " => " << value << value * it->second << std::endl;
	else
		throw(noLowerException());

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
	if(line != "date | value")
		throw(firstLineException());
	while(getline(file,line)) {

		std::string date, valueStr;
		float value;
		
		std::stringstream ss(line);
		std::getline(ss, date, '|');
		date.erase(date.size() - 1);
		std::getline(ss, valueStr, '\n');

		std::istringstream iss(valueStr.erase(0, 1));
		iss >> value;
		
		try {

			checkDate(date);

		}
		catch (std::exception &e) {

			std::cerr << e.what() << std::endl;
			continue;

		}

		try {

			checkValue(value);

		}
		catch (std::exception &e) {

			std::cerr << e.what() << std::endl;
			continue;

		}
		exchangeValue(date, value);		
	}
}
// 		This program must use a database in csv format which will represent bitcoin price
// over time

		// If the date used in the input does not exist in your DB then you
		// must use the closest date contained in your DB. Be careful to use the
		// lower date and not the upper one.

const char* BitcoinExchange::dataBaseException::what() const throw() {
	return(MYRED "Error: couldn't open the database file or it was empty" MYEOF);
}

const char* BitcoinExchange::fileException::what() const throw() {
	return(MYRED "Error: couldn't open the file or it was empty" MYEOF);
}

const char* BitcoinExchange::firstLineException::what() const throw() {
	return(MYRED "Error: first line is not exactly 'datE | value'" MYEOF);
}

BitcoinExchange::dateException::dateException(const std::string &date) {
	this->_errorMessage = "Error: bad input => " + date;
}

const char* BitcoinExchange::dateException::what() const throw() {
	return(std::string(MYRED + _errorMessage + MYEOF).c_str());
}

BitcoinExchange::dateException::~dateException() throw() {
}

const char* BitcoinExchange::tooHighValueException::what() const throw() {
	return(MYRED "Error: too large a number." MYEOF);
}

const char* BitcoinExchange::negativeNumberException::what() const throw() {
	return(MYRED "Error: not a positive number." MYEOF);
}

const char* BitcoinExchange::noLowerException::what() const throw() {
	return(MYRED "Error: no equal or lower date" MYEOF);
}
