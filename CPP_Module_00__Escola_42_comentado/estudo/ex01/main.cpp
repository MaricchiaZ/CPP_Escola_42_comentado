/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:55:02 by maclara-          #+#    #+#             */
/*   Updated: 2023/06/15 16:49:13 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
    std::string action;
    PhoneBook pb;
    int anti_loop = 0;
    
    while(1)
    {
        std::cout << "Choice 1 option: 'ADD' to create a new contact, 'SEARCH' to find a contact ou 'EXIT' to go" << std::endl;
        std::cin >> action;
        std::cout << std::endl;
        if (action[0] == '\0'){
            std::cout << "CTRL + D finish this programm" << std::endl;
            return 1;
        }
        if (anti_loop == 10)
            return 0;
        if (action == "ADD"){
            anti_loop = 0;
            pb.add();
        }
        else if (action == "SEARCH"){
            anti_loop = 0;
            pb.search_contact();
        }
        else if (action == "EXIT"){
            pb.exit();
            return 0;
        }
        else{
            std::cout << "Invalid option" << std::endl;
        }
    }
}