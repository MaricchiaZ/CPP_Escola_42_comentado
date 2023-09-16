/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample_class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:36:22 by maclara-          #+#    #+#             */
/*   Updated: 2023/06/27 14:52:02 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sample_class.hpp"

Sample::Sample(){
    std::cout << "Constructor called" << std::endl;
    return;
}

Sample::~Sample(){
    std::cout << "Destructor called" << std::endl;
    return;
}

void Sample::bar(char const c) const{
    std::cout << "Member function bar called with char overload: " << c << std::endl;
    return;
}

void Sample::bar(int const n) const{
    std::cout << "Member function bar called with int overload: " << n << std::endl;
    return;
}

void Sample::bar(float const z) const{
    std::cout << "Member function bar called with float overload: " << z << std::endl;
    return;
}

void Sample::bar(Sample const &i) const{
    (void)i; // to avoid unused variable warning (only for this example)
    std::cout << "Member function bar called with Sample overload: " << &i << std::endl;
    return;
}
