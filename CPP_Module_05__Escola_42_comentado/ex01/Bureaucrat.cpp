/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:59:15 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/02 09:47:22 by maclara-         ###   ########.fr       */
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

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high! (Grade 1 - 150)";
} 

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low! (Grade 1 - 150)";
} 

// assina o Form ou avisa o motivo de não ter assinado
void Bureaucrat::signForm(Form& form)
{
	try {
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e){
		std::cout << Bureaucrat::getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& var)
{
	out << var.getName() << ", bureaucrat grade " << var.getGrade() << std::endl;
	return out;
}
