/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:07:30 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/28 09:15:46 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>

class AMateria; //  é uma declaração antecipada (forward declaration) da classe ICharacter. 
// Isso significa que você está informando ao compilador que a classe ICharacter existe, mas ainda 
// não está definida no momento.

/*      ESSA DECLARAÇÃO SERVE COMO INTERFACE e EVITA DEPENDÊNCIAS CIRCULARES

Interface de uso: A declaração antecipada fornece uma interface de uso da classe ICharacter sem expor os detalhes 
internos de sua implementação. Isso pode ser útil se você estiver criando uma biblioteca ou uma API em que deseja 
limitar o acesso aos detalhes internos das classes.

Resolução de dependências circulares: Suponha que a classe ICharacter também dependa da classe AMateria. 
Se você incluir o cabeçalho completo de ICharacter.hpp em AMateria.hpp, e também incluir AMateria.hpp em 
ICharacter.hpp, haverá uma dependência circular, o que pode causar problemas de compilação. Usando uma 
declaração antecipada, você evita essa dependência circular.

*/



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
class ICharacter { // vai agir como uma interface, uma vez que não tem seus métodos instanciados

public:
    virtual ~ICharacter() {}
    virtual std::string const& getName() const = 0; // aqui estão as funções virtuais puras
    virtual void equip(AMateria *m)  = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter &target) = 0;

};

#endif
