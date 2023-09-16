/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:01:51 by maclara-          #+#    #+#             */
/*   Updated: 2023/06/22 18:11:07 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {   
        
public:

   Zombie();
   ~Zombie();

   //setter
   void setZombie(std::string zombies_name);
   
   //getter
   std::string getZombie()const;
   
   //functions member
   void announce(void);

private:

    std::string _my_name;
};

Zombie*	zombieHorde(int n, std::string name);

#endif