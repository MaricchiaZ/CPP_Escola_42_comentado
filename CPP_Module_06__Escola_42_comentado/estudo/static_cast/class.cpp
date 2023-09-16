/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 08:41:19 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/18 10:17:31 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

class Parent {};
class Child1 : public Parent {};
class Child2 : public Parent {};

class Unrelated {};

int main(void){
    
    Child1 a; // valor de referencia

    // Aqui ocorre um upcast implícito, onde um ponteiro Parent *b é inicializado com o endereço de a, 
    // que é um objeto da classe Child1. Isso é permitido porque Child1 é derivado de Parent, então 
    // um ponteiro de Parent pode apontar para um objeto de Child1. 
    // Nenhuma conversão é necessária neste caso.
    Parent *b = &a; // IMPLÍCITO cast de reinterpretação

    //  Isso não é permitido devido à direção da relação de herança. Seria necessário um static_cast
    //  para realizar uma conversão explícita.
    // ❌ NÂO FUNCIONA.... um cast de demoção deve ser feito de forma explícita
    Child1 *c = b; // IMPLÍCITO cast de demoção - ❌ não compila
    
    // Aqui, um static_cast é usado para converter explicitamente um ponteiro Parent *b em um 
    // ponteiro Child2 *d. Embora b aponte para um objeto de Child1, o static_cast é usado para 
    // forçar a conversão para um tipo Child2, que é uma classe derivada de Parent. 
    // No entanto, é importante notar que essa conversão é insegura, pois b aponta para um objeto
    //  de Child1, não Child2. O comportamento resultante ao usar d é indefinido.
    Child2 *d = static_cast<Child2*>(b); // EXPLÍCITO cast de demoção

    // ❌ NÂO FUNCIONA....  Essa conversão também é insegura, pois a é um objeto de Child1 e não está 
    // relacionado à classe Unrelated. O comportamento resultante ao usar e é indefinido.
    Unrelated * e = static_cast<Unrelated *>(&a); // EXPLÍCITO cast de conversão - ❌ não compila
    
    return 0;
}

/*

❌O COMPILADOR NÂO PERMITE COMPILAR POR CAUSA DO CAST DAS LINHAS 35 e 46 ❌

É importante ter cuidado ao usar static_cast e garantir que a conversão seja segura e adequada ao relacionamento entre os tipos envolvidos. Caso contrário, podem ocorrer erros e comportamentos indefinidos.

*/