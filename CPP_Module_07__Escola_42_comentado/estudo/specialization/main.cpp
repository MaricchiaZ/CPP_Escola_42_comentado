/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:43:08 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/19 11:17:56 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "pair_class.tpp"

int main(void){
    
    Pair<int, int> p1(4, 2);
    Pair<std::string, float> p2(std::string("Pi"), 3.14f);
    Pair<float, bool> p3(4.2f, true);
    Pair<bool, bool> p4(true, true);
    

    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;
    std::cout << p4 << std::endl;

    return 0;
}

/*
g++ -Wall -Wextra -Werror -Wno-unused main.cpp

~/Trabalhos/MC_42/CPP_Module_07__Escola_42/estudo/specialization ❯ ./a.out
Int partial specialization
Generic template
Generic template
Bool/bool specialization
Pair(4, 2)
Pair(Pi, 3.14)
Pair(4.2, 1)
Pair(true, true)

*/