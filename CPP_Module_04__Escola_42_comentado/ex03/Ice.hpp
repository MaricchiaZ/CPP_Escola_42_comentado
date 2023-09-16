/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:05:19 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/27 09:01:06 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"


class Ice : public AMateria {
    
public:
    Ice(void);
    ~Ice(void);
    Ice(Ice const & src);
    Ice & operator=(Ice const &src);
    
    virtual AMateria *clone() const;
    virtual void use(ICharacter &target);
};

#endif
