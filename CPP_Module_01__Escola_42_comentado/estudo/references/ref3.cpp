/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref3.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:28:29 by maclara-          #+#    #+#             */
/*   Updated: 2023/06/18 12:28:16 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Student{
    
    private:
        std::string _login;
        
    public:
    //  Student(std::string const &login): _login(login){ //  o 'const' está depois (mas pode ser antes também)
        Student(const std::string &login): _login(login){
        }
        
        std::string &getLoginRef(){
            return this->_login;
        }
        
        const std::string &getLoginRefConst() const{
            return this->_login;
        }

        std::string *getLoginPtr(){
            return &(this->_login);
        }

        const std::string *getLoginPtrConst() const{
            return &(this->_login);
        }
};

int main(){
    
    Student bob = Student("bfubar");
    Student const jim = Student("jfubar");

    std::cout << bob.getLoginRefConst() << " " << jim.getLoginRefConst() << std::endl;
    std::cout << *(bob.getLoginPtrConst()) << " " << *(jim.getLoginPtrConst()) << std::endl; // usamos pointer quando
    // vamos usar uma veriável que terá seu valor alterado, ou para apontar para algo que ainda não tem um valor

    bob.getLoginRef() = "bobfubar"; // usamos referência se NÃO iremos alterar, ou sobrescrever o valor da variável
    std::cout << bob.getLoginRefConst() << std::endl;
    
    *(bob.getLoginPtr()) = "bobbyfubar";
    std::cout << bob.getLoginRefConst() << std::endl;

    return 0;
}

// g++ ref3.cpp

/*

~/Trabalhos/MC_42/CPP_Module_01__Escola_42/ex00/estudo/references ❯ ./a.out
bfubar jfubar
bfubar jfubar
bobfubar
bobbyfubar

*/