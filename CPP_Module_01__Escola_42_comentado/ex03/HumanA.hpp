/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 08:30:29 by maclara-          #+#    #+#             */
/*   Updated: 2023/06/26 18:08:37 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA{
    
    public:

    HumanA(std::string Name, Weapon &weapon);
    ~HumanA();
    
    void    attack();

    private:
        std::string _name;
        Weapon  &weaponA;
};

#endif