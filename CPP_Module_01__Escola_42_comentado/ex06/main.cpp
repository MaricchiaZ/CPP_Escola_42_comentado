/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:05:45 by maclara-          #+#    #+#             */
/*   Updated: 2023/06/26 22:24:53 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Harl.hpp"

int	main(int argc, char* argv[]) {
	Harl harl;

	if (argc != 2) {
		harl.complain("");
		return 1;
	}
	harl.complain(argv[1]);
	
	return 0;
}

/* tente: "./Harl "  ou   "./Harl WARNING"

~/Trabalhos/MC_42/CPP_Module_01__Escola_42/ex06 ❯ ./Harl 
[ probably complaining about insignificant problems ]


~/Trabalhos/MC_42/CPP_Module_01__Escola_42/ex06 ❯ ./Harl WARNING
 I think I deserve to have some extra bacon for free. I have been coming for years whereas you started working here since last month..
This is unacceptable! I want to speak to the manager now.


~/Trabalhos/MC_42/CPP_Module_01__Escola_42/ex06 ❯ ./Harl INFO
I cannot believe adding extra bacon costs more money. You did not put enough bacon in my burger! If you did, I would not be asking for more!
 I think I deserve to have some extra bacon for free. I have been coming for years whereas you started working here since last month..
This is unacceptable! I want to speak to the manager now.


~/Trabalhos/MC_42/CPP_Module_01__Escola_42/ex06 ❯ ./Harl DEBUG
 I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!
I cannot believe adding extra bacon costs more money. You did not put enough bacon in my burger! If you did, I would not be asking for more!
 I think I deserve to have some extra bacon for free. I have been coming for years whereas you started working here since last month..
This is unacceptable! I want to speak to the manager now.


~/Trabalhos/MC_42/CPP_Module_01__Escola_42/ex06 ❯ ./Harl ERROR
This is unacceptable! I want to speak to the manager now.


*/