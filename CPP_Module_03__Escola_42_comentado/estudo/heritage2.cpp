/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heritage2.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:54:08 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/10 11:24:10 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Animal{

public:
    Animal(); // default constructor
    ~Animal(); // default destructor
    Animal(Animal const &src); // copy constructor
    Animal &operator=(Animal const &src); // assignation operator overload

    void run(int distance);
    void call();
    void eat(std::string const &what);
    void walk(int distance);

private:
    int _numberOfLegs;
};

class Otter : public Animal{ // a classe Otter herda da classe Animal
    
public:
    Otter(); // default constructor
    ~Otter(); // default destructor
    Otter(Otter const &src); // copy constructor
    Otter &operator=(Otter const &src); // assignation operator overload
    
};

class Cat : public Animal{ // a classe Cat herda da classe Animal
    
public:
    Cat(); // default constructor
    ~Cat(); // default destructor
    Cat(Cat const &src); // copy constructor
    Cat &operator=(Cat const &src); // assignation operator overload

    void scornSomeone(std::string const &target);
};

class Pony : public Animal{ // a classe Pony herda da classe Animal
    
public:
    Pony(); // default constructor
    ~Pony(); // default destructor
    Pony(Pony const &src); // copy constructor
    Pony &operator=(Pony const &src); // assignation operator overload

    void doMagic(std::string const &target);
};
