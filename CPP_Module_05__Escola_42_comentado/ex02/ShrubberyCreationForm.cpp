/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:39:47 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/28 09:40:02 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm() {
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubbery) : AForm(shrubbery) {
	*this = shrubbery;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubbery) {
	(void)shrubbery;
 	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target):
 AForm("Shrubbery Creation Form", 145, 137) {
	this->setTarget(target);
}

void ShrubberyCreationForm::execute(const Bureaucrat & executor) const {
	if (this->getSigned() == false) {
		throw AForm::UnsignedFormException();
	}
	else if (executor.getGrade() > this->getGradeToExecute()) {
		throw AForm::GradeTooLowException();
	}
	else {
		std::ofstream outfile (this->getTarget().c_str());   
		std::string tree =   
"                                                         . \n"
"                                              .         ; \n"  
"                 .              .              ;%     ;; \n"   
"                   ,           ,                :;%  %; \n"
"                    :         ;                   :;%;'     ., \n"
"           ,.        %;     %;            ;        %;'    ,; \n"
"             ;       ;%;  %%;        ,     %;    ;%;    ,%' \n"
"              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
"               ;%;      %;        ;%;        % ;%;  ,%;' \n"
"                `%;.     ;%;     %;'         `;%%;.%;' \n"
"                 `:;%.    ;%%. %@;        %; ;@%;%' \n"
"                    `:%;.  :;bd%;          %;@%;' \n"
"                      `@%:.  :;%.         ;@@%;' \n"
"                        `@%.  `;@%.      ;@@%; \n"
"                          `@%%. `@%%    ;@@%; \n"
"                            ;@%. :@%%  %@@%; \n"
"                              %@bd%%%bd%%:; \n"
"                                #@%%%%%:;; \n"
"                                %@@%%%::; \n"
"                                %@@@%(o);  . ' \n"
"                                %@@@o%;:(.,' \n"
"                            `.. %@@@o%::; \n"
"                               `)@@@o%::; \n"
"                                %@@(o)::; \n"
"                               .%@@@@%::; \n"
"                               ;%@@@@%::;. \n"
"                              ;%@@@@%%:;;;. \n"
"                          ...;%@@@@@%%:;;;;,.. \n";
		outfile << tree;
		outfile.close();
	}

}
