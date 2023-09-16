/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:39:56 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/28 09:40:06 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm {
    
public:
    ShrubberyCreationForm(void);
    ~ShrubberyCreationForm(void);
    ShrubberyCreationForm(const ShrubberyCreationForm &shrubbery);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &shrubbery);

    ShrubberyCreationForm(const std::string target);

    void execute(Bureaucrat const & executor) const;
        
};

#endif
