/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:01:58 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/22 19:32:07 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Essa função  é responsável por calcular o resultado de uma expressão aritmética
//  no formato Notação Polonesa Reversa (RPN). Ela utiliza uma pilha (std::stack) para 
// armazenar os valores numéricos intermediários e operar sobre eles conforme os operadores 
// são encontrados na expressão.
double RPNcalculate(std::string arg)
{
	std::stack<double> rpn; // definimos uma pilha chamada rpn para armazenar os valores
    //  numéricos intermediários, e um contador i para percorrer a string arg.
	int i = 0;

	while (arg[i]) // o loop é usado para percorrer cada caractere da string arg.
	{
		double number;
		if (arg[i] > 47 && arg[i] < 58) // Se o caractere atual for um dígito (0 a 9)
		{
			std::string str_number; // representa o número completo
			while (arg[i] > 47 && arg[i] < 58) { // um loop interno é iniciado para preencher a string
            //  number que representa o número completo. Isso permite lidar com números de vários dígitos. 
				str_number += arg[i];
				i++;
			}
			std::istringstream(str_number) >> number; // A string str_number é convertida em um valor numérico 
            // number usando std::istringstream.
			rpn.push(number); // O valor number é empilhado na pilha rpn.
		}
		else if (arg[i] == ' ') // Se o caractere atual for um espaço em branco, ele é simplesmente ignorado.
			i++;
		else if (arg[i] == '+' || arg[i] == '-' || arg[i] == '*' || arg[i] == '/') // Se o caractere atual for um 
        // dos operadores aritméticos (+, -, *, /), dois números da pilha rpn são desempilhados e a operação aritmética
        //  correspondente é realizada. O resultado é empilhado de volta na pilha rpn.
		{
			double number_1;
			double number_2;
			double result;
			if (rpn.size() < 2)
				throw "Error";
			number_2 = rpn.top();
			rpn.pop();
			number_1 = rpn.top();
			rpn.pop();
			if (arg[i] == '+')
				result = number_1 + number_2;
			if (arg[i] == '-')
				result = number_1 - number_2;
			if (arg[i] == '*')
				result = number_1 * number_2;
			if (arg[i] == '/')
				result = number_1 / number_2;
			rpn.push(result);
			i++; // O loop continua avançando até que todos os caracteres da string arg sejam processados.
		}
		else // Se o caractere atual não se encaixar nas condições anteriores, um erro é lançado indicando uma expressão inválida.
			throw "ERROR: invalid caracter.";
	}
	if (rpn.size() != 1) // é verificado se a pilha rpn contém exatamente um valor. Se não, um erro é lançado indicando um erro na expressão.
		throw "Error: RPN error execution.";
	else
		return (rpn.top()); //  O retorno é o resultado final que é o valor no topo da pilha rpn
}
