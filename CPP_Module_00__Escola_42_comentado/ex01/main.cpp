/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:55:02 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/24 14:28:39 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
    std::string action; // vamos usar objeto action da classe string do namespace std da biblioteca <iostream>
    PhoneBook pb; // instanciamos um objeto pb da classe Phonebook
    int anti_loop = 0; // vamos usar esse int para evitar loop eterno
    
    while(1)
    {
        std::cout << "Choice 1 option: 'ADD' to create a new contact, 'SEARCH' to find a contact ou 'EXIT' to go" << std::endl;// escrevemos essa frase no terminal
        std::cin >> action; // guardamos o retorno do usuário na variável action
        std::cout << std::endl; // quebramos uma linha
        if (action[0] == '\0'){ // se a pessoa der CTRL + D, teremos a posição 0 da string escrita como \0
            std::cout << "CTRL + D finish this programm" << std::endl; // saímos do programa
            return 1;
        }
        if (anti_loop == 10) // se entrar em loop e der 10 voltas
            return 0; // paramos o loop e encerramos o programa
        if (action == "ADD"){ // se a pessoa escrever ADD
            anti_loop = 0; // zeramos a variável de verificar o loop
            pb.add(); // acessamos a função add do objeto pb
        }
        else if (action == "SEARCH"){ // ou, se a pessoa escrever SEARCH
            anti_loop = 0; // zeramos a variável de verificar o loop
            pb.search_contact(); // acessamos a função search_contact do objeto pb
        }
        else if (action == "EXIT"){  // ou, se a pessoa escrever EXIT
            exit(0); // saímos do programa
        }
        else{ // e se não for nada disso
            std::cout << "Invalid option" << std::endl; // escrevemos no terminal que a frase da pessoa está inválida
        }
    }
}
