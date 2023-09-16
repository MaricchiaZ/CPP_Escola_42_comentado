/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:53:39 by maclara-          #+#    #+#             */
/*   Updated: 2023/06/27 14:55:25 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sample_class.hpp"

int main(void){
    Sample instance;

    instance.bar('a');
    instance.bar(42);
    instance.bar(3.14f);
    instance.bar(instance);

    return (0);
}

/*
g++ -Wall -Wextra -Werror -std=c++98 *.cpp -o polymorphism


~/Trabalhos/MC_42/CPP_Module_02__Escola_42/estudo/polymorphism ❯ ./polymorphism 
Constructor called
Member function bar called with char overload: a
Member function bar called with int overload: 42
Member function bar called with float overload: 3.14
Member function bar called with Sample overload: 0x7ffd0791f0b7
Destructor called

*/