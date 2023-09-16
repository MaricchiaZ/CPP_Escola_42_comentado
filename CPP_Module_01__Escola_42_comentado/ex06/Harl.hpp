/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:44:41 by maclara-          #+#    #+#             */
/*   Updated: 2023/06/26 22:06:54 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl{
    public:

    Harl();
    ~Harl();
    
    void complain(std::string level);
    void printLevel(std::string level) const;
    
    private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    
};

#endif