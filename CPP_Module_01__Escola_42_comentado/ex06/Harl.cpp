/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:44:10 by maclara-          #+#    #+#             */
/*   Updated: 2023/06/26 22:20:07 by maclara-         ###   ########.fr       */
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
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*fun[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	int	i = -1;
	for ( i = 0; i < 4; i++)
	{
		if (!level.compare(levels[i])) {
			break ;
		}
	}
	switch (i)
	{
	case 0:
		(this->*fun[0])();
		__attribute__((fallthrough)); // O atributo fallthrough é útil em situações em que você deseja que o código 
		//em um caso de switch execute tanto o código desse caso quanto o código do caso seguinte, sem precisar 
		//repetir o código ou usar uma pausa explícita (como o break),  ou seja, o código do caso seguinte
		// será executado também.
	case 1:
		(this->*fun[1])();
		__attribute__((fallthrough));
	case 2:
		(this->*fun[2])();
		__attribute__((fallthrough));
	case 3:
		(this->*fun[3])();
		break ;
	default:
		printLevel("probably complaining about insignificant problems");
		break ;
	}
}

void	Harl::printLevel(std::string level) const {
	std::cout << "[ " << level << " ]" << std::endl;
}