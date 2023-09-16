/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poly2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:12:17 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/11 16:33:40 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

/*                               ---- SÓ PARA EXEMPLO ----

Método puro: é um método virtual que não possui implementação na classe base, mas deve ser implementado em todas as classes derivadas.

Nesse código, temos as seguintes classes:

- ACharacter: É uma classe abstrata que possui um método virtual puro attack e um método não virtual sayHello. Ela também tem um membro privado name. Um objeto dessa classe não pode ser criado diretamente devido ao método virtual puro.

- Warrior: É uma subclasse de ACharacter que sobrescreve o método sayHello. O método attack não é sobrescrito, pois é um método virtual puro.

- ICoffeeMaker: É uma classe abstrata que define duas funções virtuais puras fillWaterTank e makeCoffee. Essas funções não têm implementação nessa classe e devem ser implementadas nas subclasses.
*/

class ACharacter{ // o A indica que é uma classe abstrata (clean code)
    public:
        virtual void attack(std::string const &target) = 0; 
        void sayHello(std::string const &target);
    private:
        std::string name;
};

class Warrior : public ACharacter{
    public:
        virtual void sayHello(std::string const &target);
};

void ACharacter::sayHello(std::string const &target){
    std::cout << "Hello " << target << "!" << std::endl;
}

void Warrior::sayHello(std::string const &target){
    std::cout << "*attacks " << target << " with a sword*" << std::endl;
}

class ICoffeeMaker{
public:
    virtual void fillWaterTank(IWaterSource *src) = 0;
    virtual ICoffee* makeCoffee(std::string const & type) = 0;
}
int main(){
    
    ACharacter* a = new Warrior(); // É criado um objeto Warrior chamado a, referenciado por um 
    // ponteiro ACharacter. Isso é possível porque Warrior é uma subclasse de ACharacter.
    
    ACharacter* b = new ACharacter(); //  Essa linha não é válida, pois ACharacter é uma classe abstrata 
    // e não pode ser instanciada diretamente. O compilador não permitirá essa atribuição direta. 

    a->sayHello("students");
    a->attack("roger");

    /*
    O método sayHello chamará a implementação sobrescrita na classe Warrior, enquanto o método attack 
    não tem uma implementação específica na classe Warrior, pois é um método virtual puro na classe ACharacter.
    */
}

