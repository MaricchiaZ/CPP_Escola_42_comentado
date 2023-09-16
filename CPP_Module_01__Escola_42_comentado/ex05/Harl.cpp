/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:44:10 by maclara-          #+#    #+#             */
/*   Updated: 2023/06/26 21:58:48 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl:: Harl(void){
}

 Harl::~ Harl(void){
}

void Harl::debug(void)
{
	std::cout << " I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You did not put enough bacon in my burger! If you did, I would not be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << " I think I deserve to have some extra bacon for free. I have been coming for years whereas you started working here since last month.." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void  Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG","INFO","WARNING","ERROR"};
	void (Harl::*fun[4])(void) = { &Harl::debug,&Harl::info,&Harl::warning,&Harl::error};
	
	int tab = (
		(level == "DEBUG") * 0 + (level == "INFO") * 1 +
		(level == "WARNING") * 2 + (level == "ERROR") * 3);
	(this->*fun[tab])();
}
