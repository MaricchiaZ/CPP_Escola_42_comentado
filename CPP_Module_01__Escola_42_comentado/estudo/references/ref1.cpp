/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref1.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:56:30 by maclara-          #+#    #+#             */
/*   Updated: 2023/06/18 11:13:13 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(){
    
    int numberOfBalls = 42;
    
    int *ballsPtr = &numberOfBalls; // ponteiro (exatamente como usamos em c)
    int &ballsRef = numberOfBalls; // referência (conceito novo do CPP)

    std::cout << numberOfBalls << " " << *ballsPtr << " " << ballsRef << std::endl;
    
    *ballsPtr = 21; // aqui precisamos do * para modificar o valor original de numberOfBalls
    std::cout << numberOfBalls<< std::endl;
    ballsRef = 84; // aqui a referência (quando declarada a variável ballsRef) tranforma-a em um alias, que ao ser
    // chamada está representando a variável numberOfBalls para sempre
    std::cout << numberOfBalls<< std::endl;

}

// g++ ref1.cpp

/*

~/Trabalhos/MC_42/CPP_Module_01__Escola_42/ex00/estudo/references ❯ ./a.out
42 42 42
21
84

*/