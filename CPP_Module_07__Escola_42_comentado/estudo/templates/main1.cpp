/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:24:19 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/19 08:37:22 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// SEM TEMPLATE
// Se tivermos uma função que retorna o marior valor entre dois valores inteiros, podemos TAMBÉM criar 
// uma função para retornar o maior valor entre dois valores float, ou entre dois valores char, ou entre
//  dois valores double, etc. Mas isso seria muito trabalhoso, pois teríamos que criar uma função para 
// cada tipo de dado que quiséssemos comparar. Para isso, podemos usar templates.
int max(int x, int y) {
    return (x >= y ? x : y);
}

// COM TEMPLATE
// podemos trocar o tipo de dado que a função recebe e retorna por um tipo genérico, que será definido 
// na chamada da função. O tipo de dado genérico pode ser usado em qualquer lugar que um tipo de dado 
// normal seria usado.

template <typename T> //Usamos a palavra-chave template, seguida do tipo de dado genérico (T) e o nome 
// da função. O tipo de dado genérico pode ser qualquer nome, mas é comum usar T, U, V, etc.

T max(T x, T y) {
    return (x >= y ? x : y);
}
// aqui a função retorna uma cópia do valor máximo encontrado.


// COM TEMPLATE recebendo uma referência constante...
//  Isso permite que a função seja utilizada com tipos imutáveis e evita cópias desnecessárias.
template <typename T>

T const & max(T const & x, T const & y) {
    return (x >= y ? x : y);
}
// aqui a função retorna uma referência constante para o valor máximo encontrado.

/*
A escolha entre retornar uma cópia (T) ou uma referência constante (T const &) depende do contexto e dos requisitos do programa.

Quando retornamos uma cópia (T), estamos criando uma nova instância do valor máximo e retornando essa cópia. Isso significa que a função max retorna um valor independente das variáveis originais x e y. O resultado da função pode ser armazenado em uma variável separada.

Por outro lado, quando retornamos uma referência constante (T const &), estamos retornando uma referência para um dos parâmetros x ou y que representa o valor máximo. Nesse caso, não estamos criando uma nova instância do valor máximo, mas sim retornando uma referência para o valor existente nas variáveis x ou y. Isso significa que o resultado da função estará vinculado às variáveis originais e qualquer alteração nessas variáveis será refletida no resultado.

*/