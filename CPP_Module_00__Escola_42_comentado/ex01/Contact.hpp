/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:47:16 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/24 14:27:25 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class Contact {
    
public:

    Contact(); //Construtor
    ~Contact(); // Destrutor
    
// MEMBROS -  termo "membro" refere-se a qualquer entidade (variável, função ou classe) que faz parte de uma classe

// Métodos: Também chamado de "função membro" ou "método de classe", é uma função declarada dentro de uma classe

// accessors (ou acessadores) referem-se a funções-membro especiais de uma classe que permitem acessar e modificar os
//  atributos privados da classe. Essas funções fornecem uma interface controlada para obter e definir os valores dos 
// atributos da classe.
    //  acessadores- set - Setter (Acessor de escrita): É uma função-membro que é usada para definir (ou modificar) 
    // o valor de um atributo privado da classe
    void	setFirstName(std::string s);
    void	setLastName(std::string s);
    void	setNickname(std::string s);
    void	setPhoneNumber(std::string s);
    void	setDarkestSecret(std::string s);
    //  acessadores - get - Getter (Acessor de leitura): É uma função-membro que é usada para obter o valor de um 
    // atributo privado da classe. 
    std::string	getFirstName(void);
    std::string	getLastName(void);
    std::string	getNickname(void);
    std::string	getPhoneNumber(void);
    std::string	getDarkestSecret(void);


private:

// Atributo: Também conhecido como "variável de membro", é uma variável declarada dentro de uma classe. 
//Cada objeto criado a partir da classe terá uma cópia independente dos atributos da classe
    std::string first_name; // O namespace 'std' é uma parte importante da biblioteca padrão do C++, que 
    // contém diversas classes, funções e objetos úteis para programação. Por exemplo, a classe std::string. 
    // 'first_name' é uma variável do tipo std::string, que é uma classe do C++ para manipulação de strings. 
    // Podemos usar fist_name como uma string de C
    std::string last_name;
    std::string	nickname;
    std::string	phone_number;
	std::string	darkest_secret;
        
};

#endif
