/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inheritance.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:45:29 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/10 10:52:04 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Cat{

public:
    Cat(); // default constructor
    ~Cat(); // default destructor
    Cat(Cat const &src); // copy constructor
    Cat &operator=(Cat const &src); // assignation operator overload

    void run(int distance);
    void scornSomeone(std::string const &target);

private:
    int _numberOfLegs;
    
};

class Pony{

public:
    Pony(); // default constructor
    ~Pony(); // default destructor
    Pony (Pony const &src); // copy constructor
    Pony &operator=(Pony const &src); // assignation operator overload

    void run(int distance);
    void doMagic(std::string const &target);

private:
    int _numberOfLegs;
    
};