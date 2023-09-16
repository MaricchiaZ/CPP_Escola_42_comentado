/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:44:41 by maclara-          #+#    #+#             */
/*   Updated: 2023/06/26 21:48:29 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl{
    public:
    void complain(std::string level);
    
    Harl();
    ~Harl();
    
    private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    
};

#endif