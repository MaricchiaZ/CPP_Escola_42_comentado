/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:11:30 by maclara-          #+#    #+#             */
/*   Updated: 2023/06/26 18:20:27 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB {

    public:
        HumanB(std::string name);
        ~HumanB();
        
        void attack();
        void setWeapon(Weapon& weapon);
    private:
        std::string _name;
        Weapon* weaponB;
};

#endif