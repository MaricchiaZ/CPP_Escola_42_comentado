/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:37:15 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/19 09:45:44 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vertex_class.tpp"

int main(void){
    
    Vertex<int> v1(12, 23, 34);
    Vertex<> v2(12, 23, 34);

    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;

    return 0;
}

/*

g++ -Wall -Wextra -Werror -Wno-unused main.cpp

~/Trabalhos/MC_42/CPP_Module_07__Escola_42/estudo/default_type ❯ ./a.out
Vertex(12, 23, 34)
Vertex(12.0, 23.0, 34.0)


*/