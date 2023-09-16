/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poly2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:12:17 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/11 16:02:19 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>


/*
Aqui temos uma hierarquia de classes envolvendo personagens (characters). 
A classe base é Character, que contém um método virtual sayHello. 
Em seguida, temos a classe Warrior, que herda de Character e substitui o método sayHello com sua própria implementação. 
Também temos a classe Cat, que também herda de Character.
*/
class Character{
    public:
        virtual void    sayHello(std::string const &target);
};

class Warrior : public Character{
    public:
        virtual void    sayHello(std::string const &target);
};

class Cat{
};

void Character::sayHello(std::string const &target){
    std::cout << "Hello " << target << "!" << std::endl;
}

void Warrior::sayHello(std::string const &target){
    std::cout << "F*** off " << target << ", I don't like you!" << std::endl;
}

// Aqui vemos algumas demonstrações de polimorfismo de subtipos:
int main(){
    // A criação de um objeto Warrior usando um ponteiro para Warrior é válida, pois um Warrior é um Warrior.
    Warrior* a = new Warrior();

    // A criação de um objeto Warrior usando um ponteiro para Character também é válida, pois um Warrior
    //  é um Character.
    Character* b = new Warrior();
    
    // A tentativa de criar um objeto Character usando um ponteiro para Warrior não é válida, pois um Character
    //  não é necessariamente um Warrior (embora a relação seja válida no sentido inverso).

    // O compilador não permitirá essa atribuição direta, por isso a flag "-fpermissive" na compilação
    Warrior* c = new Character();

    // A tentativa de criar um objeto Cat usando um ponteiro para Character também não é válida, pois Cat
    //  e Character são tipos completamente diferentes e não estão relacionados.
    //Character* d = new Cat();

    a->sayHello("students");
    b->sayHello("students");

    /*
    Por fim, chamamos o método sayHello em ambos os objetos a e b, que são ponteiros para Warrior e Character, respectivamente. 
    Devido ao polimorfismo de subtipos, a função apropriada é chamada para cada objeto. 
    No caso do objeto a, que é um Warrior, a versão substituída do método sayHello em Warrior é chamada. 
    Para o objeto b, que é um ponteiro para Character, mas aponta para um objeto Warrior, a versão substituída também é chamada. 
    Isso mostra como o polimorfismo de subtipos permite que objetos de diferentes classes sejam tratados de maneira uniforme por meio de um ponteiro ou referência à classe base.
    */
}

/*
g++ -fpermissive poly2.cpp

~/Trabalhos/MC_42/CPP_Module_04__Escola_42/estudo/polymorphism_and_sub-typing ❯ ./a.out 
F*** off students, I don't like you!
F*** off students, I don't like you!

*/

/*
a é um guerreiro e se comporta como um guerreiro

já o b é um personagem, mas se comporta como um guerreiro

Quando chamamos o método sayHello usando o ponteiro b, o compilador usa a tabela de funções virtuais (tabela VTable) para determinar qual implementação do método deve ser chamada. Nesse caso, como b aponta para um objeto Warrior, a implementação do método sayHello na classe Warrior é executada, mesmo que o ponteiro seja declarado como um ponteiro para Character. Isso é possível porque o método sayHello é declarado como virtual na classe base Character. Isso permite que o compilador determine qual implementação do método deve ser chamada com base no tipo real do objeto apontado pelo ponteiro, em vez do tipo declarado do ponteiro.

*/