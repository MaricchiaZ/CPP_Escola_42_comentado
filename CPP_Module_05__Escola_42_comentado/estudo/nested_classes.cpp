/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nested_classes.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:47:57 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/13 10:50:02 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Cat{

public:
    class Leg{
        ....
    };
    
};

class Dog{

public:
    class Leg{
        ....
    };
    
};

int main(
    Cat somecat;
    Cat::Leg somecatleg;
)