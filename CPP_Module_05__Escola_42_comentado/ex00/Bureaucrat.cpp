/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:59:15 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/02 09:18:48 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("me") {
	std::cout << "Bureaucrat Default constructer called" << std::endl;
	this->grade = 150;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructer called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
	std::cout<< "Bureaucrat copy constructer called" << std::endl;
    *this = src;
}

Bureaucrat &Bureaucrat::operator= (const Bureaucrat &src) {
    static_cast<std::string>(this->name) = src.getName();
	this->grade = src.grade;
    return (*this);
}

Bureaucrat::Bureaucrat(std::string const name, int grade):name(name) {
	std::cout << "Bureaucrat parametric constructer called" << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = grade;
}

void Bureaucrat::incrementGrade() {
	if ((this->getGrade() - 1) < 1)
		throw GradeTooHighException();
	else
		this->grade--;
}

void Bureaucrat::decrementGrade() {
	if ((this->getGrade() + 1) > 150)
		throw GradeTooLowException();
	else
		this->grade++;
}

std::string const Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

// Quando um erro é detectado, é possível lançar uma exceção usando a palavra-chave "throw". 
//Uma exceção é um objeto que carrega informações sobre o erro ou situação excepcional que ocorreu.

// Quando uma exceção é lançada dentro do bloco "try", o programa procura um bloco "catch" correspondente 
// para tratar essa exceção. Se um bloco "catch" adequado é encontrado, o código dentro dele é executado para 
// lidar com a exceção. Caso contrário, o programa termina abruptamente, exibindo uma mensagem de erro padrão (segmentation fault).

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high! (Grade 1 - 150)";
} 

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low! (Grade 1 - 150)";
} 

// operador << imprime o level do burocrata
std::ostream& operator<<(std::ostream& out, const Bureaucrat& var)
{
	out << var.getName() << ", bureaucrat grade " << var.getGrade() << std::endl;
	return out;
}
