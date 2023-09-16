/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:41:46 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/08 12:07:15 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
#define EASYFIND_H

# include <iostream>
# include <vector>
# include <algorithm>
# include <iterator>

// Definimos uma classe chamada NotFound que herda da classe std::exception. Essa classe 
// NotFound é uma classe de exceção personalizada que é usada para sinalizar quando um valor 
// procurado não foi encontrado em um contêiner.
class NotFound : public std::exception // A classe std::exception é a classe base para todas
//  as exceções padrão do C++. Ao herdar dela, você pode criar suas próprias exceções personalizadas
//  com comportamento e mensagens de erro específicos.
{
// a classe NotFound sobrescreve a função what(), que é uma função virtual pura da classe base std::exception. 
// A função what() retorna uma mensagem de erro explicando que o valor procurado não foi encontrado no contêiner.
    public:
        const char* what() const throw(){
            return ("Infortunatly dosn't exist in this container\n");
        }
}; //  Essa classe personalizada NotFound é utilizada para criar exceções com uma mensagem de erro específica sempre 
// que a função easyfind não encontra o valor procurado no contêiner.

//  essa função easyfind permite encontrar um valor específico dentro de um contêiner do tipo T, usando a 
// função std::find, e retorna um iterador para esse valor. Se o valor não for encontrado, ele lança uma 
// exceção chamada NotFound. Isso pode ser útil para buscar valores em diversos tipos de contêineres (vetores, 
// listas, mapas, etc.) de uma forma genérica.

template <typename T> //  Isso indica que o código é um modelo (template) e que depende de um tipo de dado T.
typename T::iterator easyfind(T& intContainer, int val) { // Esta é a definição da função chamada easyfind. Ela 
// recebe dois parâmetros: um contêiner (que deve ser do tipo que tem um membro iterator) e um valor inteiro que
//  você deseja encontrar.
    typename T::iterator iter = std::find(intContainer.begin(), intContainer.end(), val); // typename T::iterator: Isso indica
    //  que o tipo de retorno da função é um "iterator" pertencente ao tipo T. std::find(intContainer.begin(), 
    // intContainer.end(), val): Isso chama a função std::find da STL, que tenta encontrar o valor val dentro do 
    // intervalo definido pelos iteradores begin() e end() do contêiner intContainer.
    if (iter == intContainer.end()){ // Se o iterador iter for igual a end(), isso significa que o valor não foi
    //  encontrado no contêiner. Nesse caso, a função lança uma exceção chamada NotFound.
        throw NotFound();
    }
        
	return iter; // Se o valor for encontrado, a função retorna o iterador que aponta para o elemento encontrado.
}

#endif
