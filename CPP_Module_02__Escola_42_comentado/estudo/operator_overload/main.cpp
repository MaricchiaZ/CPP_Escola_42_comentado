/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:46:51 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/03 13:07:18 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "integer_class.hpp"

int main(){
    Integer x(30);
    Integer y(10);
    Integer z(0);

    std::cout << "Value of x: " << x << std::endl;
    std::cout << "Value of y: " << y << std::endl;
    y = Integer(12); // novo constructor
    std::cout << "Value of y: " << y << std::endl;
    
    std::cout << "Value of z: " << z << std::endl;
    z = x + y;
    std::cout << "Value of z: " << z << std::endl;
    return 0;
}

/*
g++ -Wall -Wextra -Werror -pedantic -std=c++98 *.cpp


~/Trabalhos/MC_42/CPP_Module_02__Escola_42/estudo/operator_overload ❯ ./a.out
Constructor called with value 30
Constructor called with value 10
Constructor called with value 0
Value of x: 30
Value of y: 10
Constructor called with value 12
Assignment operator called from 10 to 12
Destructor called with value 12
Value of y: 12
Value of z: 0
Addition operator called with 30 and 12
Constructor called with value 42
Assignment operator called from 0 to 42
Destructor called with value 42
Value of z: 42
Destructor called with value 42
Destructor called with value 12
Destructor called with value 30

*/