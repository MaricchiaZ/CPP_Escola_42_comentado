/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:24:10 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/25 10:19:23 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
    
public:
    Fixed(void); // FORMA CANONICA - constructor
    ~Fixed(void); // FORMA CANONICA - destructor
    
    Fixed(Fixed const & src); // FORMA CANONICA - cópia do constructor
    Fixed & operator=(Fixed const & src); // FORMA CANONICA - ATRIBUIÇÃO de cópia

// acessadores
    void setRawBits(int const bits);
    int getRawBits(void) const;
    
private:

    int _fixedPointValue;
    static int const _fractionalBits;
};
#endif