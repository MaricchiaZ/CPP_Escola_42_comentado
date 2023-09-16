/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:37:12 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/03 21:14:11 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sample_class.hpp"

int main (){
    Sample instance1;
    Sample instance2(42);
    Sample instance3(instance1);

    std::cout << instance1 << std::endl;
    std::cout << instance2 << std::endl;
    std::cout << instance3 << std::endl;

    instance3 = instance2;
    std::cout << instance3 << std::endl;

    return 0;
}

/*
g++ sample_class.cpp main.cpp

~/Trabalhos/MC_42/CPP_Module_02__Escola_42/estudo/canonical_form ❯ ./a.out 
DEFAULT Constructor called
PARAMETRIC Constructor called
COPY Constructor called
Assignation operator called
The value of _foo is: 0
The value of _foo is: 42
The value of _foo is: 0
Assignation operator called
The value of _foo is: 42
Destructor called
Destructor called
Destructor called

*/