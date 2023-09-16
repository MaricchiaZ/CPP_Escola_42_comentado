/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stl2.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:30:24 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/19 19:39:50 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Esse código utiliza a biblioteca <algorithm> do C++ para demonstrar o uso da função std::for_each juntamente com um iterador de lista (std::list<int>) para exibir os elementos da lista.
*/

#include <iostream>
#include <algorithm>
#include <list>

void displayInt(int i){
    std::cout << i << std::endl;
}

int main(void){

    // Inicialmente, uma lista chamada lst é criada e alguns valores inteiros são adicionados a ela
    //  usando o método push_back.
    std::list<int> lst;

    lst.push_back(10);
    lst.push_back(23);
    lst.push_back(3);
    lst.push_back(17);
    lst.push_back(20);

    std::cout << "List contains: " << std::endl;
    /*
    A função std::for_each é chamada passando como argumentos os iteradores lst.begin() e lst.end(), que representam o início e o fim da lista, respectivamente.
    A função displayInt é fornecida como um terceiro argumento, que será aplicada a cada elemento da lista e simplesmente imprime o valor do inteiro recebido como parâmetro.
    */
    std::for_each(lst.begin(), lst.end(), displayInt);
    
    return (0);
}