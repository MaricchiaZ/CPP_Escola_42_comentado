/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 09:16:46 by maclara-          #+#    #+#             */
/*   Updated: 2023/06/26 18:53:18 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon{
    
    public:

    Weapon(std::string Type);
    ~Weapon();
    
    void    setType(std::string Type);
    std::string getType() const;

    private:
        std::string _type;
};

#endif