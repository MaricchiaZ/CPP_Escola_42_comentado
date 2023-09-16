/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:23:27 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/28 09:39:59 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    
public:
    RobotomyRequestForm(void);
    ~RobotomyRequestForm(void);
    RobotomyRequestForm(const RobotomyRequestForm &robot);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &robot);

    RobotomyRequestForm(const std::string target);

    void execute(Bureaucrat const & executor) const;
        
};

#endif
