/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:24:10 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/04 21:20:25 by maclara-         ###   ########.fr       */
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
    
    //funções novas do ex01
    float toFloat(void) const;
    int toInt(void) const;

//funções novas do ex02

    // 6 operadores de comparação:  >,  <,  >=,  <=,  ==, !=
    bool	operator>(Fixed const& other) const;
    bool	operator<(Fixed const& other) const;
    bool	operator>=(Fixed const& other) const;
    bool	operator<=(Fixed const& other) const;
    bool	operator==(Fixed const& other) const;
    bool	operator!=(Fixed const& other) const;

    // 4 operadores aritméticos:  +,  -,  * e  /
    Fixed	operator+(Fixed const& other) const;
    Fixed	operator-(Fixed const& other) const;
    Fixed	operator*(Fixed const& other) const;
    Fixed	operator/(Fixed const& other) const;

    // Pré-incremento  e  pós-incremento
    Fixed & operator++(void);
    Fixed	operator++(int);
    
    // Pré-decremento  e  pós-decremento
    Fixed & operator--(void);
    Fixed	operator--(int);
    
    // Funções  de  membro  sobrecarregadas
    static Fixed & min(Fixed & f1, Fixed & f2);
    static Fixed const & min(Fixed const & f1, Fixed const & f2);

    static Fixed & max(Fixed & f1, Fixed & f2);
    static Fixed const & max(Fixed const & f1, Fixed const & f2);
    
private:
    int _fixedPointValue;
    static int const _fractionalBits;
};

std::ostream &operator <<(std::ostream &out, Fixed const &f); //  Aqui vai a sobrecarga do operador de
// inserção («) que insere uma representação de ponto flutuante do número de ponto fixo no objeto de  
// fluxo de saída passado como parâmetro

#endif