/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 09:10:48 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/02 09:48:46 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class AForm{ // AForm é uma classe abstrata que serve de base para as classes
// concretas ShrubberyCreationForm, RobotomyRequestForm e PresidentialPardonForm

public:
    // forma canônica
    AForm();
    virtual ~AForm();
    AForm(const AForm &src);
    AForm& operator=(const AForm &src);
    
    // construtor paramétrico
    AForm(const std::string name, int gradeToSign, int gradeToExecute);

    //setters
    void setTarget(std::string target);

    // getters
    std::string getName()const;
    bool getSigned()const;
    int getGradeToSign()const;
    int getGradeToExecute()const;
    const std::string getTarget(void) const;
    
    // função de assinar
    void beSigned(Bureaucrat &bureaucrat);

    // função de executar
    virtual void execute(Bureaucrat const & executor) const = 0;

    //standard exception(exception)
    class GradeTooHighException: public std::exception // classe aninhada
    {
        public:
            const char* what() const throw();
    };

    class GradeTooLowException: public std::exception // classe aninhada
    {
        public:
            const char* what() const throw();
    };
    class UnsignedFormException: public std::exception
    {
        public:
            const char* what() const throw();
    };

protected:
    const std::string target;

private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;
    
};

std::ostream & operator<<(std::ostream & o, AForm const & AForm);

#endif
