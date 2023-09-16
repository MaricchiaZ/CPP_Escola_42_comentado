/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:27:37 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/02 10:29:08 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
    
	public:
	  	Intern(void);
		~Intern(void);
		Intern(const Intern &intern);
		Intern &operator=(const Intern &intern);

		// retornam um ponteiro para um objeto Form
		AForm* makeForm(const std::string name, const std::string target);
		AForm* createPresidentialForm(const std::string target) const;
		AForm* createRobotomyForm(const std::string target) const;
		AForm* createShrubberyForm(const std::string target) const;

		class InvalidFormException : public std::exception { // classe aninhada
			public:
				const char* what(void) const throw();
  		};
}; // sem características próprias

#endif
