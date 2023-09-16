/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stl1.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:12:43 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/19 19:30:05 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <vector>
#include <list>


/*
O código apresentado demonstra o uso de alguns contêineres do C++: std::list, std::map e std::vector.
*/

class IOperation;

int main(){
    std::list<int> lst1;
    std::map<std::string, IOperation*> map1;
    /*
    std::vector é um contêiner sequencial que armazena elementos em um array dinamicamente redimensionável. No código, v1 é um vetor vazio e v2 é um vetor de tamanho fixo com 42 elementos, cada um com o valor 100.
    */
    std::vector<int> v1;
    std::vector<int> v2(42, 100);
    
    /*
    std::list é um contêiner sequencial que armazena elementos em uma lista duplamente encadeada. No código, lst1 é uma lista de números inteiros. Os elementos são adicionados à lista usando o método push_back.
    */
    lst1.push_back(1);
    lst1.push_back(17);
    lst1.push_back(42);

    /*
    std::map é um contêiner associativo que armazena pares chave-valor. No código, map1 é um mapa que associa strings a ponteiros de IOperation. São adicionados dois elementos ao mapa usando a sintaxe map1["key"] = value, onde "key" é uma string e value é um ponteiro para um objeto IOperation.
    */
    map1["opA"] = new OperationA();
    map1["opB"] = new OperationB();

    /*
    Além disso, é criado um iterador it do tipo std::list<int>::const_iterator para percorrer a lista lst1. Um segundo iterador it6 é inicializado com o valor de lst1.end(), que representa o final da lista
    */
    std::list<int>::const_iterator it;
    std::list<int>::const_iterator it6 = lst1.end();

    // Um loop for é usado para iterar sobre os elementos da lista e imprimir seu valor.
    for (it = lst1.begin(); it != it6; ++it)
        std::cout << *it << std::endl;
    
    return 0;
}

/*
É importante notar que a classe IOperation é mencionada, mas não está definida no código fornecido. Presume-se que ela seja uma classe derivada que possui as operações "opA" e "opB" implementadas.

Em resumo, o código ilustra o uso básico de contêineres como std::list, std::map e std::vector, bem como o uso de iteradores para percorrer e acessar os elementos desses contêineres.
*/