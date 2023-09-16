/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:43:37 by maclara-          #+#    #+#             */
/*   Updated: 2023/06/26 22:03:35 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl;

	std::cout << "DEBUG: " << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;
    
	std::cout << "INFO: " << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;
    
	std::cout << "WARNING: " << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;
    
	std::cout << "ERROR: " << std::endl;
	harl.complain("ERROR");    
	std::cout << std::endl;
    return 0;
}