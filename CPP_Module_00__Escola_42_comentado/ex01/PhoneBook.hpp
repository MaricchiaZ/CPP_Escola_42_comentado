/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:46:22 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/24 14:27:43 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <string>
# include <sstream>
# include <cstdlib>

class PhoneBook{
    
public:

    PhoneBook(); // Construtor
    ~PhoneBook(); // Destrutor 

// Métodos (funções membros): 
    void search_contact(void);
    void add(void);
	void printInfo(Contact contact, int index);
	void printContact(Contact contact);

private:
    // atributos
    Contact    list_contacts[8]; // temos um array de objetos da classe Contat
    int nbr_contact; // uma variável pra o número de contatos 
    int index; // uma variável para atuar como índice de onde salvar os contatos
    
};

#endif
