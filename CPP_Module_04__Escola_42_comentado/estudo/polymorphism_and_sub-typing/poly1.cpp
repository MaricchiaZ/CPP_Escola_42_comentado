/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poly1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:12:17 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/11 14:00:02 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

/*
Nesse código, temos três classes: Character, Warrior e Cat, onde Warrior e Cat são subclasses de Character. Cada classe tem um método sayHello implementado.

- A classe Character possui um método sayHello que imprime "Hello" seguido do argumento target.
- A classe Warrior é uma subclasse de Character e também possui seu próprio método sayHello, que imprime uma mensagem específica para um guerreiro.
- A classe Cat também é uma subclasse de Character, mas não tem uma implementação própria para o método sayHello. Portanto, usará a implementação da classe Character.
*/
class Character{
    public:
        void    sayHello(std::string const &target);
};

class Warrior : public Character{
    public:
        void    sayHello(std::string const &target);
};

class Cat {
};

void Character::sayHello(std::string const &target){
    std::cout << "Hello " << target << "!" << std::endl;
}

void Warrior::sayHello(std::string const &target){
    std::cout << "F*** off " << target << ", I don't like you!" << std::endl;
}

int main(){
    // A criação de um objeto Warrior usando um ponteiro para Warrior é válida, pois um Warrior é um Warrior.
    Warrior* a = new Warrior();

    // A criação de um objeto Warrior usando um ponteiro para Character também é válida, pois um Warrior
    //  é um Character.
    Character* b = new Warrior();
    
    // A tentativa de criar um objeto Character usando um ponteiro para Warrior não é válida, pois um Character
    //  não é necessariamente um Warrior (embora a relação seja válida no sentido inverso).

    //O compilador não permitirá essa atribuição direta, por isso a flag "-fpermissive" na compilação
    Warrior* c = new Character();

    // A tentativa de criar um objeto Cat usando um ponteiro para Character também não é válida, pois Cat
    //  e Character são tipos completamente diferentes e não estão relacionados.
    Character* d = new Cat();

    a->sayHello("students");
    b->sayHello("students");

    /*
    Em seguida, são feitas chamadas para o método sayHello em a e b, que imprimirão mensagens diferentes. A chamada a->sayHello("students") chamará o método sayHello da classe Warrior, enquanto a chamada b->sayHello("students") chamará o método sayHello da classe Character, pois a resolução será baseada no tipo real do objeto b, que é um Character.
    */
}

/*
g++ -fpermissive poly1.cpp

~/Trabalhos/MC_42/CPP_Module_04__Escola_42/estudo/polymorphism_and_sub-typing ❯ ./a.out 
F*** off students, I don't like you!
Hello students!

*/

/*
a é um guerreiro e se comporta como um guerreiro

já o b é um personagem, então se comporta como personagem, mesmo que tenha recebido as características de um guerreiro

*/