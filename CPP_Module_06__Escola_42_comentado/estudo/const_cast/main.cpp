/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:25:04 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/18 10:37:49 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Aqui temos o uso de const_cast para remover a qualificação const de um ponteiro para int. 
int main(void){
    
    int a = 42; // Valor de referência

    int const * b = &a; // IMPLÍCITO cast de promoção
    // b é um ponteiro constante para um inteiro é declarado e aponta para a variável a. 
    // Isso significa que o valor apontado pelo ponteiro não pode ser modificado através desse ponteiro.

    
    int * c = b; // EXPLÍCITO cast de demoção - ❌não funciona
    // Aqui ocorre uma atribuição implícita, onde o ponteiro constante b é atribuído a um ponteiro 
    // não constante c. Isso não é permitido pelo compilador

    
    int * d = const_cast<int *>(b); // EXPLÍCITO cast de demoção por const_cast
    // Aqui é usado const_cast para remover a qualificação const do ponteiro b.
    //  Isso permite a conversão de um ponteiro constante para um ponteiro não constante. 
    // o entanto, é importante ressaltar que o uso de const_cast para remover a qualificação const só é seguro
    //  se o objeto original não for realmente constante. Caso contrário, a modificação de um objeto 
    // originalmente constante pode levar a comportamento indefinido.
}

/*

O const_cast é usado para modificar a qualificação const de um objeto ou ponteiro, permitindo que o objeto ou ponteiro seja tratado como não constante. No entanto, é importante usá-lo com cuidado e garantir que o objeto original não seja realmente constante antes de usar o const_cast. Se ele estava declarado como const, provavelmente ele foi declarado assim por um motivo, e modificar um objeto originalmente constante pode levar a comportamento indefinido, já que ele teve seu valor modificado e não se comportará como anteriormente.

*/