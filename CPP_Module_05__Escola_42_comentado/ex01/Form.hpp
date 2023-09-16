/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 09:10:48 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/02 09:27:38 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form{

public:
    // forma canônica
    Form();
    ~Form();
    Form(const Form &src);
    Form& operator=(const Form &src);
    
    // construtor paramétrico
    Form(const std::string name, int gradeToSign, int gradeToExecute);

    // getters
    std::string getName()const;
    bool getSigned()const;
    int getGradeToSign()const;
    int getGradeToExecute()const;
    
    // função de assinar
    void beSigned(Bureaucrat &bureaucrat);

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

private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;
    
};

std::ostream & operator<<(std::ostream & o, Form const & Form);

#endif
