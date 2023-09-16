/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:46:17 by maclara-          #+#    #+#             */
/*   Updated: 2023/06/15 16:56:48 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
    this->nbr_contact = 0;
    this->index = 0;
    return ;
}

PhoneBook::~PhoneBook(void){
    return ;
}

void    PhoneBook::add(void){

    Contact new_contact;
    std::string temp_buffer;
    
    std::cin.ignore(); // a função ignore do objeto std::cin descarta qualquer caractere pendente no buffer de entrada.
    std::cout << "Add Contact infos" << std::endl;
    
    // get de First Name and save in new_contact
    temp_buffer = "";
    std::cout << "First name: ";
    std::cin >> temp_buffer;
    if (temp_buffer == "") {
        std::cout << "Invalid input" << std::endl << std::endl;
        return ;
    }
    new_contact.setFirstName(temp_buffer);

    // get Last Name and save in new_contact
    temp_buffer = "";
    std::cout << "Last Name: ";
    std::cin >> temp_buffer;
    if (temp_buffer == "") {
        std::cout << "Invalid input" << std::endl << std::endl;
        return ;
    }
    new_contact.setLastName(temp_buffer);
    
    // get Nickname and save in new_contact
    temp_buffer = "";
    std::cout << "Nickname: ";
    std::cin >> temp_buffer;
    if (temp_buffer == "") {
        std::cout << "Invalid input" << std::endl << std::endl;
        return ;
    }
    new_contact.setNickname(temp_buffer);

    // get Phone number and save in new_contact
    temp_buffer = "";
    std::cout << "Phone number: ";
    std::cin >> temp_buffer;
	if (temp_buffer == "" || temp_buffer.find_first_not_of("0123456789") != std::string::npos) {
		std::cout << "Invalid input" << std::endl << std::endl;
		return ;
    }
    // verifica se há algum caractere no número de telefone que não seja um dígito de 0 a 9. O método 
    // find_first_not_of é usado para encontrar o primeiro caractere que não faz parte da lista de dígitos fornecida.
    new_contact.setPhoneNumber(temp_buffer);

    // get Darkest secret and save in new_contact
    temp_buffer = "";
    std::cout << "Darkest secret: ";
    std::cin >> temp_buffer;
    if (temp_buffer == "") {
        std::cout << "Invalid input" << std::endl << std::endl;
        return ;
    }
    new_contact.setDarkestSecret(temp_buffer);

    list_contacts[this->index] = new_contact;
    this->index++;
	if (this->nbr_contact < 8)
		this->nbr_contact++;
	if (this->index == 8)
		this->index = 0;
	return ;
}

void    PhoneBook::search_contact(void){
    
	std::stringstream str_to_int;
	int	index = -1;
    
    std::cout << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|"<< std::endl;
	for (int i = 0; i < this->nbr_contact; i++) {
		this->printInfo(this->list_contacts[i], i);
	}
    std::string	id;
    std::cout << "Insert ID to search (0 - 8): ";
    std::cin >> id;
    std::cout << std::endl;
    str_to_int << id;
    str_to_int >> index;
    if (id != "" && id.find_first_not_of("0123456789") && 0 <= index && index < this->nbr_contact)
        this->printContact(this->list_contacts[index]);
    else
        std::cout << "Invalid Input" << std::endl;
}

void	PhoneBook::printContact(Contact contact) {
	std::cout << "First name : " << contact.getFirstName() << std::endl;
	std::cout << "Last name : " << contact.getLastName() << std::endl;
	std::cout << "Nickname : " << contact.getNickname() << std::endl;
	std::cout << "Phone number : " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret : " << contact.getDarkestSecret() << std::endl << std::endl;
}

void	PhoneBook::printInfo(Contact contact, int index) {
	Contact	format = contact;

	if (format.getFirstName().length() > 10) {
		format.setFirstName(format.getFirstName().substr(0, 9) + '.');
	}
	if (format.getLastName().length() > 10) {
		format.setLastName(format.getLastName().substr(0, 9) + '.');
	}
	if (format.getNickname().length() > 10) {
		format.setNickname(format.getNickname().substr(0, 9) + '.');
	}
	if (format.getPhoneNumber().length() > 10) {
		format.setPhoneNumber(format.getPhoneNumber().substr(0, 9) + '.');
	}
	if (format.getDarkestSecret().length() > 10) {
		format.setDarkestSecret(format.getDarkestSecret().substr(0, 9) + '.');
	}
	std::cout << "|" << std::setw(10) << index; // A função std::setw(10) é usada para definir uma largura 
    // fixa de 10 caracteres para cada campo exibido. 
	std::cout << "|" << std::setw(10) << format.getFirstName();
	std::cout << "|" << std::setw(10) << format.getLastName();
	std::cout << "|" << std::setw(10) << format.getNickname() << "|" << std::endl;
}

void    PhoneBook::exit(void){
   this->~PhoneBook();
    return ;
;}

