/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:46:14 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/03 13:31:59 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGER_CLASS_H
# define INTEGER_CLASS_H

#include <iostream>

class Integer {
    
public:
    Integer(int const n);// O construtor Integer é declarado e recebe um parâmetro int const n. Ele será usado para inicializar um objeto Integer com um valor inteiro.
    ~Integer(void);

    int     getValue(void) const; //O método getValue é declarado como uma função membro pública e retorna o valor inteiro armazenado no objeto Integer.
    
    Integer &   operator=(Integer const & rhs); //O operador de atribuição operator= é declarado como uma função membro da classe Integer. Ele permite a atribuição de um objeto Integer a outro objeto Integer.
    // Integer& operator=(Integer const& rhs);:
    // Nesse caso, o operador de atribuição (operator=) retorna uma referência (&) para o objeto Integer. 
    // Isso permite que você encadeie várias atribuições consecutivas. Por exemplo: 
    // Integer a, b, c;
    // a = b = c; // Encadeamento de atribuições
    
    Integer     operator+(Integer const & rhs) const; //permite a adição de dois objetos Integer, retornando um novo objeto Integer que contém a soma dos valores.
    // Nesse caso, o operador de adição (operator+) retorna uma cópia (Integer) do objeto resultante da operação.
    // Como a cópia é feita, o objeto original não é modificado. Portanto, não é necessário usar o operador &.

    /*
    A decisão de usar o operador & ou não depende do comportamento desejado para cada operador sobrecarregado.
     O uso de & permite modificar o objeto original, enquanto a ausência de & retorna uma cópia do objeto resultante.
    */

private:

    int     _n;
};

std::ostream &  operator<<(std::ostream & o, Integer const & rhs); // operador de inserção operator<< é declarado fora da classe Integer como uma função global. Ele permite a impressão de um objeto Integer em um fluxo de saída, como std::cout.

// std::ostream & o: É uma referência ao objeto de fluxo de saída, onde o objeto Integer será impresso.

// Integer const & rhs: É uma referência constante ao objeto da classe Integer, que será impresso no fluxo de saída.

#endif

/*
Ao sobrecarregar esses operadores, você pode definir o comportamento desejado para essas operações quando aplicadas a objetos da classe Integer. Isso proporciona uma maior flexibilidade e naturalidade no uso desses operadores com objetos personalizados.
*/