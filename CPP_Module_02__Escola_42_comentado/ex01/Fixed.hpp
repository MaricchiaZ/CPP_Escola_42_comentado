/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:24:10 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/25 14:32:31 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath> // roundf

class Fixed {
    
public:
    Fixed(void); // FORMA CANONICA - constructor
    
    Fixed(const int nb); //  constructor parametrico
    Fixed(const float nb); // constructor parametrico

    ~Fixed(void); // FORMA CANONICA - destructor
    
    Fixed(Fixed const & src); // FORMA CANONICA - cópia do constructor
    Fixed & operator=(Fixed const & src); // FORMA CANONICA - ATRIBUIÇÃO de cópia

    void setRawBits(int const bits);
    int getRawBits(void) const;
    
    float toFloat(void) const; //funções novas do ex01
    int toInt(void) const; //funções novas do ex01
    
private:
    int _fixedPointValue;
    static int const _fractionalBits;
};

std::ostream &operator <<(std::ostream &out, Fixed const &f); //  Aqui vai a sobrecarga do operador de
// inserção («) que insere uma representação de ponto flutuante do número de ponto fixo no objeto de  
// fluxo de saída passado como parâmetro

#endif
