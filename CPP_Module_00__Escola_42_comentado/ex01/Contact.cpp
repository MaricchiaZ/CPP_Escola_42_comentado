/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:47:11 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/24 14:28:23 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Construtor Contact::Contact(void): Esse é o construtor padrão da classe Contact. Como não possui parâmetros, 
// é conhecido como construtor padrão sem argumentos. O construtor é chamado automaticamente quando um objeto da
//  classe é criado. Nesse caso, ele não realiza nenhuma ação, pois o corpo do construtor está vazio (return;). 
// Isso é comum quando não é necessário realizar inicializações ou outras operações no momento da criação do objeto.
Contact::Contact(void){ 

    return ;
}


// Destrutor Contact::~Contact(void): Esse é o destrutor da classe Contact. O destrutor é chamado automaticamente 
// quando um objeto da classe é destruído, seja quando ele sai de escopo ou quando é explicitamente deletado com o
//  operador delete. Assim como o construtor, o destrutor também não realiza nenhuma ação específica, pois o corpo 
// do destrutor está vazio (return;). É comum que um destrutor vazio seja definido quando não há necessidade de liberar 
// recursos ou realizar outras operações de limpeza ao destruir o objeto.
Contact::~Contact(void){

    return ;
}

// as funções SET vão atribuir um valor para cada variável da classe
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

// as funções GET acessam as variáveis da classe e retornam com o valor da variável acessada
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
