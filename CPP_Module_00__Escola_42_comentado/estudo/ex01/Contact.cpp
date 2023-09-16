/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:47:11 by maclara-          #+#    #+#             */
/*   Updated: 2023/06/14 21:00:20 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setFirstName(std::string s) {
	this->first_name = s;
}

void	Contact::setLastName(std::string s) {
	this->last_name = s;
}

void	Contact::setPhoneNumber(std::string s) {
	this->phone_number = s;
}

void	Contact::setNickname(std::string s) {
	this->nickname = s;
}

void	Contact::setDarkestSecret(std::string s) {
	this->darkest_secret = s;
}

std::string	Contact::getFirstName(void) {
	return (this->first_name);
}

std::string	Contact::getLastName(void) {
	return (this->last_name);
}

std::string	Contact::getNickname(void) {
	return (this->nickname);
}

std::string	Contact::getPhoneNumber(void) {
	return (this->phone_number);
}

std::string	Contact::getDarkestSecret(void) {
	return (this->darkest_secret);
}

Contact::Contact(void){

    return ;
}

Contact::~Contact(void){

    return ;
}