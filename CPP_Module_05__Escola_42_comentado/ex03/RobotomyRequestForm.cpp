/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:23:38 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/28 09:40:55 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm() {
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robot) : AForm(robot) {
	*this = robot;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &robot) {
	(void)robot;
 	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): 
 AForm("Robotomy Request Form", 72, 45) {
	this->setTarget(target);
}

void RobotomyRequestForm::execute(const Bureaucrat & executor) const {
	if (this->getSigned() == false) {
		throw AForm::UnsignedFormException();
	}
	else if (executor.getGrade() > this->getGradeToExecute()) {
		throw AForm::GradeTooLowException();
	}
	else {
        int nbr = rand();
        if (nbr % 2 != 0)
			std::cout << "That " << this->getTarget() << " has been robotomized!" << std::endl; 
		else {
			std::cout << "Robotomization has failed!" << std::endl; 	
		}
	}

}
