/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:45:36 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/08 10:29:23 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

/*
Essa função template iter é útil quando se deseja realizar uma operação em cada elemento de um array  
 de forma genérica, sem a necessidade de escrever loops repetitivos para diferentes tipos de arrays ou funções 
 de processamento. Ela permite a reutilização de código para diferentes tipos de dados e funções de processamento.
*/

template <typename T>
void iter(T *arr, int len, void(*func)(T const &ref)) // A função iter itera sobre o array, chamando a função
//  fornecida
{
	if (arr == NULL || len == 0 || func == NULL)
		return ;
	
	for (int i = 0; i < len; i++)
		func(arr[i]); // Dentro do loop, a função func é chamada para cada elemento do array, passando
        //  o elemento como referência constante. Isso permite que a função func realize alguma operação 
        // ou processamento no elemento do array.
}


template<typename T> //  Isso define um template de função que aceita um tipo de dado T
void print(T const & p) //  Isso define a assinatura da função print, que aceita uma referência constante p do tipo T.
{
	std::cout << p << std::endl; // . Essa função é projetada para imprimir o valor de um objeto passado como parâmetro.
	// O template permite que você use a mesma função para diferentes tipos de dados, pois o tipo é determinado quando a função é chamada.
}

#endif
