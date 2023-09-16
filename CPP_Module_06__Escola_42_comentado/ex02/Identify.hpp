/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:06:42 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/07 20:24:06 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

# include <iostream>
# include "Base.hpp"
# include "Derived.hpp"

// void identify(Base * p) -> Imprime o tipo real do objeto apontado por p: "A", "B" ou "C"
// por meio de PONTEIRO
void    identify( Base* p ) {
    if ( dynamic_cast< A* >( p ) )
        std::cout << "Type: A" << std::endl;
    else if ( dynamic_cast< B* >( p ) )
        std::cout << "Type: B" << std::endl;
    else if ( dynamic_cast< C* >( p ) )
        std::cout << "Type: C" << std::endl;
    else
        std::cout << "unknown" << std::endl;
}

// void identificar(Base & p) -> Imprime o tipo real do objeto apontado por p: "A", "B" ou "C".
// por meio de REFERÊNCIA
void    identify( Base& p ) {
    try {
        A& a = dynamic_cast< A& >( p );
        std::cout << "Type: A" << std::endl;
        (void)a;
    } 
    catch(const std::exception& e) {
        try {
            B& b = dynamic_cast< B& >( p );
            std::cout << "Type: B" << std::endl;
            (void)b;
        } 
        catch( const std::exception& e ) {
            try {
                C& c = dynamic_cast< C& >( p );
                std::cout << "Type: C" << std::endl;
                (void)c;
            }
            catch( const std::exception& e ) {
                std::cout << "unknown" << std::endl;
            }
        }
    }
 
}

#endif
