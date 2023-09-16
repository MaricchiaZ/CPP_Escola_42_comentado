/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:53:13 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/28 09:39:50 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTALPARDONFORM_HPP
# define PRESIDENTALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    
public:
    PresidentialPardonForm(void);
    ~PresidentialPardonForm(void);
    PresidentialPardonForm(const PresidentialPardonForm &p);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &p);

    PresidentialPardonForm(const std::string target);

    void execute(Bureaucrat const & executor) const;
        
};

#endif
