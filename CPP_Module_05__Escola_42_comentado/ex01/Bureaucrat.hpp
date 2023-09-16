/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:59:10 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/02 09:46:49 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat
{

public:
    // Canonical Form
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& src);
    Bureaucrat& operator=(const Bureaucrat& src);
    
    Bureaucrat(std::string const name, int grade);
    
    // Accessor-get
    std::string const getName() const;
    int getGrade() const;
    
    void incrementGrade();
    void decrementGrade();
    void signForm(Form &form); // implementada segundo o pdf

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
    std::string const name;
    int		grade;

};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& var);

#endif