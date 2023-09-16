/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:13:45 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/28 09:16:39 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include <string>
#include "AMateria.hpp"


/*
INTERFACE 

Em C++98, a linguagem não possui um conceito direto de "interfaces" como em algumas outras linguagens de programação, 
como Java ou C#. No entanto, é comum referir-se a classes abstratas puras como "interfaces" em C++98, pois elas 
desempenham um papel semelhante ao das interfaces nessas outras linguagens.

Uma classe abstrata é uma classe que contém PELO MENOS UMA função virtual pura. Uma função virtual pura é declarada 
usando a sintaxe 'virtual returnType functionName() = 0;' na classe base. Uma classe abstrata não pode ser instanciada 
diretamente; em vez disso, ela serve como uma classe base para outras classes derivadas, que implementam as funções virtuais puras.

Assim, uma classe abstrata fornece uma "interface" para outras classes que desejam herdar dela. Essa interface 
é composta pelas funções virtuais puras declaradas na classe abstrata, que as classes derivadas são obrigadas a implementar.

Vale ressaltar que, embora as classes abstratas puras sejam comumente chamadas de "interfaces" em C++98, elas não são 
idênticas às interfaces encontradas em linguagens como Java ou C#. As interfaces nessas outras linguagens permitem apenas 
declaração de métodos, sem a implementação, e uma classe pode implementar várias interfaces. Em C++98, as classes abstratas 
puras PODEM TER ATRIBUTOS E MÉTODOS COM IMPLEMENTAÇÕES, e uma classe pode herdar apenas de uma única classe abstrata.
 
*/

class IMateriaSource { // essa classe vai agir como interface 
    
public:
    virtual ~IMateriaSource(){}

    virtual void learnMateria(AMateria*) = 0; // e possui apenas métodos virtuais puros
    virtual AMateria* createMateria(std::string const & type) = 0;
};
#endif
