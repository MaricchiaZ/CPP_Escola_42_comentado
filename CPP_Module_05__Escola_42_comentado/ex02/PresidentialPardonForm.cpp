/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:19:10 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/28 09:39:46 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm() {
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &pardon) : AForm(pardon) {
	*this = pardon;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &pardon) {
	(void)pardon;
 	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target):
 AForm("Presidential Pardon Form", 25, 5) {
	this->setTarget(target);
}

void PresidentialPardonForm::execute(const Bureaucrat & executor) const {
	if (this->getSigned() == false) {
		throw AForm::UnsignedFormException();
	}
	else if (executor.getGrade() > this->getGradeToExecute()) {
		throw AForm::GradeTooLowException();
	}
	else {
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
	}

}
