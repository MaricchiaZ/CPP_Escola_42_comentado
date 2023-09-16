/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:46:22 by maclara-          #+#    #+#             */
/*   Updated: 2023/06/14 19:51:09 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <string>
# include <sstream>

class PhoneBook{
    
public:

    void search_contact(void);
    void add(void);
    void exit(void);
	void printInfo(Contact contact, int index);
	void printContact(Contact contact);

    PhoneBook();
    ~PhoneBook();

private:

    Contact    list_contacts[8];
    int nbr_contact;
    int index;
    
};

#endif