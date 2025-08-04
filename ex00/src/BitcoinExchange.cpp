/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 01:09:13 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/08/04 02:02:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

BitcoinExchange::BitcoinExchange() {

	//reads from file
	std::ifstream	file(FILEPATH);
	if(!file.is_open())
		throw(dataBaseException());
		
	std::string		line;
	std::getline(file, line);
	if(line.empty())
		throw(fileException());

	while(std::getline(file, line)) {

		std::string date, exchangeRateStr;
		float exchangeRate = 0.0;

		std::stringstream ss(line);
		//std::getline(input_stream, target_string [, delimiter]);
		std::getline(ss, date, ',');
		std::getline(ss, exchangeRateStr, '\n');

		//safe: string to number
		std::istringstream iss(exchangeRateStr);
		iss >> exchangeRate;

		this->_data[date] = exchangeRate;

	}

	file.close();

}

BitcoinExchange::~BitcoinExchange() {	
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy) {
	this->_data = copy._data;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const &rhs) {
	if (this != &rhs)
		this->_data = rhs._data;
	return (*this);
}

void	BitcoinExchange::checkDate(std::string date) {

	int	year;
	int	month;
	int	day;

	char dashChar1;
	char dashChar2;

	std::stringstream ss(date);

	ss >> year >> dashChar1 >> month >> dashChar2 >> day;
	if (year < 0 || year > 999999 || month < 1 || month > 12 || day < 1 || day > 31)
		throw(dateException(date));
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30))
		throw(dateException(date));
	else if ((year % 4 == 0 && month == 2 && day !=29) || (year % 4 == 0 && month == 2 && day !=28))
		throw(dateException(date));

}

void	BitcoinExchange::checkValue(float value) {
	if (value > 1000)
		throw(tooHighValueException());
	else if(value < 0)
		throw(negativeNumberException());
}

void	BitcoinExchange::exchangeValue(std::string const &date, float value) {
	
	//lower_bound >= key
	std::map<std::string, float>::iterator it = _data.lower_bound(date);
	
	if (it != _data.end() && date == it->first)
		std::cout << date << " => " << value << " = " << std::setprecision(2) << value * it->second << std::endl;
	else if(it != _data.begin()) {
		--it;
		std::cout << date << " => " << value << " = "  << std::setprecision(2) << value * it->second << std::endl;
	}
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

		size_t pipePos = line.find('|');
		if (pipePos == std::string::npos)
			std::getline(ss, date, '\n');
		else {
			std::getline(ss, date, '|');
			if (!date.empty() && date[date.size() - 1] == ' ')
				date.erase(date.size() - 1);
		}

		try {
			checkDate(date);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			continue;
		}

		std::getline(ss, valueStr, '\n');
		if (!valueStr.empty() && valueStr[0] == ' ')
			valueStr.erase(0, 1);
		std::stringstream ssValue(valueStr);
		ssValue >> value;

		try {
			checkValue(value);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			continue;
		}

		try {
			exchangeValue(date, value);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			continue;
		}

	}
}

const char* BitcoinExchange::dataBaseException::what() const throw() {
	return(MYRED "Error: couldn't open the file" MYEOF);
}

const char* BitcoinExchange::fileException::what() const throw() {
	return(MYRED "Error: the file was empty" MYEOF);
}

const char* BitcoinExchange::firstLineException::what() const throw() {
	return(MYRED "Error: first line is not exactly 'date | value'" MYEOF);
}

BitcoinExchange::dateException::dateException(const std::string &date) {
	this->_errorMessage = std::string(MYRED) + "Error: bad date input => " + date + std::string(MYEOF);
}

const char* BitcoinExchange::dateException::what() const throw() {
	return(_errorMessage.c_str());
}

BitcoinExchange::dateException::~dateException() throw() {
}

const char* BitcoinExchange::tooHighValueException::what() const throw() {
	return(MYRED "Error: too large number." MYEOF);
}

const char* BitcoinExchange::negativeNumberException::what() const throw() {
	return(MYRED "Error: not a positive number." MYEOF);
}

const char* BitcoinExchange::noLowerException::what() const throw() {
	return(MYRED "Error: no equal or lower date" MYEOF);
}
