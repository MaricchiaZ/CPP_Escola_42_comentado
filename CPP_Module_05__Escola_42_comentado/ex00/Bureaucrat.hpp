/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:59:10 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/02 07:38:03 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
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


    //  Essas classes são usadas para criar exceções personalizadas que podem ser 
    // lançadas quando ocorrem situações específicas durante a execução do programa.

    //standard exception(exception)
    class GradeTooHighException: public std::exception // classe aninhada, que é uma subclasse da classe std::exception
    {
        // As classes aninhadas herdam da classe std::exception, que é uma classe base padrão para exceções em C++. Ao herdar 
        // dessa classe, as exceções personalizadas ganham funcionalidades importantes, como a capacidade de fornecer uma mensagem 
        // de erro descritiva por meio da função what().
        public:
            const char* what() const throw(); // A função what() é declarada nas classes aninhadas, para retornar uma  string que 
            // descreve o motivo da exceção. Essa mensagem de erro é utilizada para informar ao usuário o que aconteceu de errado
            //  no programa quando a exceção é capturada e tratada.
    };


    // Por exemplo, ao lançar a exceção GradeTooHighException, o programa pode fornecer uma mensagem como "A nota é muito baixa" para 
    // indicar que a nota informada é menor do que o permitido.
    class GradeTooLowException: public std::exception // classe aninhada, que é uma subclasse da classe std::exception
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
