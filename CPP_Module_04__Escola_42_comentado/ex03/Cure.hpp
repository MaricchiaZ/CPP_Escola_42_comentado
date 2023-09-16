/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:05:42 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/27 09:01:00 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Cure : public AMateria {
    
public:
    Cure();
    ~Cure(void);
    Cure(Cure const &src);
    Cure & operator=(Cure const &src);
    
    Cure(std::string const &type);

    virtual AMateria *clone() const;
    virtual void use(ICharacter &target);

};

#endif
