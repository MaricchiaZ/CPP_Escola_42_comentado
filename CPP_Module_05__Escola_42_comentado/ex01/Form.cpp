/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 09:10:37 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/02 09:29:53 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// FORMA CANONICA - CONSTRUTOR
Form::Form(void): _name("doc"),  _signed(false), _gradeToSign(150), _gradeToExecute(150) {
    std::cout << "Constructor Default called" << std::endl;
    return;
}

// FORMA CANONICA - DESTRUTOR
Form::~Form(){
    std::cout << "Destructor called" << std::endl;
    return;
}

// FORMA CANONICA - CÓPIA DO CONSTRUTOR
Form::Form(const Form & src): _name("doc"),  _signed(false), _gradeToSign(150), _gradeToExecute(150){
    std::cout << "Copy Constructor called" << std::endl;
    *this = src;
	if (this->getGradeToSign() < 1 || this->getGradeToExecute() < 1) {
    	throw GradeTooHighException();
	}
	if (this->getGradeToSign() > 150 || this->getGradeToExecute() > 150) {
		throw GradeTooLowException();
	}
    return;
}

//  CONSTRUTOR PARAMÉTRICO	
Form::Form(const std::string name, int gradeToSign, int gradeToExecute):
 _name(name),  _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << "Parametric Constructor called" << std::endl;
	if (this->getGradeToSign() < 1 || this->getGradeToExecute() < 1) {
    	throw GradeTooHighException();
	}
	if (this->getGradeToSign() > 150 || this->getGradeToExecute() > 150) {
		throw GradeTooLowException();
	}
}

// FORMA CANONICA - ATRIBUIÇÃO
Form & Form::operator=(Form const & src){
    
    std::cout << "Copy assignment operator called" << std::endl;
	static_cast<std::string>(this->_name) = src.getName();
    this->_signed = src.getSigned();
    const_cast<int&>(this->_gradeToSign) = src.getGradeToSign();
    const_cast<int&>(this->_gradeToExecute) = src.getGradeToExecute();
    return *this;
}

std::string Form::getName(void) const {
    return this->_name;
}

bool Form::getSigned(void) const {
    return this->_signed;
}

int Form::getGradeToSign(void) const {
    return this->_gradeToSign;
}

int Form::getGradeToExecute(void) const {
    return this->_gradeToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->_signed = true;
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high! (Grade 1 - 150)";
} 

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low! (Grade 1 - 150)";
} 

// avisa se está assinado ou não e qual o level necessário de 
std::ostream & operator<<(std::ostream & o, Form const & Form) {
	o << "___ FORM: "<< Form.getName() << " ___" << std::endl;
	o << "Is signed: ";
	if (Form.getSigned())
		o << "yes" << std::endl;
	else
		o << "no" << std::endl;
	o << "Grade to sign: " << Form.getGradeToSign() << std::endl;
	o << "Grade to execute: " << Form.getGradeToExecute() << std::endl;
	return o;
}
