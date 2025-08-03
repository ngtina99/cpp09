/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 01:07:16 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/08/03 23:36:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

int	main(int argc, char **argv)
{

	if (argc != 2) {
		std::cerr << MYRED "Error: the program works with 1 filename as an argument" MYEOF << std::endl;
		exit(1);
	}

	try {
		BitcoinExchange bitcoinExchange;
		bitcoinExchange.fileReader(argv[1]);
	}
	catch ( std::exception &e ) {
		std::cerr << e.what() << std::endl;
	}

}
