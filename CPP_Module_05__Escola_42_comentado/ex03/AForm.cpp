/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 09:10:37 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/17 14:10:57 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// FORMA CANONICA - CONSTRUTOR
AForm::AForm(void): _name("doc"),  _signed(false), _gradeToSign(150), _gradeToExecute(150) {
    std::cout << "Constructor Default called" << std::endl;
    return;
}

// FORMA CANONICA - DESTRUTOR
AForm::~AForm(){
    std::cout << "Destructor called" << std::endl;
    return;
}

// FORMA CANONICA - CÓPIA DO CONSTRUTOR
AForm::AForm(const AForm & src): _name("doc"),  _signed(false), _gradeToSign(150), _gradeToExecute(150){
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
AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute):
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
AForm & AForm::operator=(AForm const & src){
    
    std::cout << "Copy assignment operator called" << std::endl;
	static_cast<std::string>(this->_name) = src.getName();
    this->_signed = src.getSigned();
    const_cast<int&>(this->_gradeToSign) = src.getGradeToSign();
    const_cast<int&>(this->_gradeToExecute) = src.getGradeToExecute();
	this->setTarget(src.getTarget());
    return *this;
}

void AForm::setTarget(std::string target) {
	const_cast<std::string&>(this->target) = target;
}


std::string AForm::getName(void) const {
    return this->_name;
}

bool AForm::getSigned(void) const {
    return this->_signed;
}

int AForm::getGradeToSign(void) const {
    return this->_gradeToSign;
}

int AForm::getGradeToExecute(void) const {
    return this->_gradeToExecute;
}

const std::string AForm::getTarget(void) const {
	return (this->target);
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->_signed = true;
	else
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high! (Grade 1 - 150)";
} 

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low! (Grade 1 - 150)";
}

const char* AForm::UnsignedFormException::what() const throw() {
	return "The form is not signed!";
} 

std::ostream & operator<<(std::ostream & o, AForm const & AForm) {
	o << "___ FORM: "<< AForm.getName() << " ___" << std::endl;
	o << "Is signed: ";
	if (AForm.getSigned())
		o << "yes" << std::endl;
	else
		o << "no" << std::endl;
	o << "Grade to sign: " << AForm.getGradeToSign() << std::endl;
	o << "Grade to execute: " << AForm.getGradeToExecute() << std::endl;
	return o;
}
