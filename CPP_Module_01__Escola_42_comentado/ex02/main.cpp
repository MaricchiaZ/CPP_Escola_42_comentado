/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:23:02 by maclara-          #+#    #+#             */
/*   Updated: 2023/06/22 18:31:49 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void byPtr(std::string *str){
    
    *str += " and ponies";
}

void byConstPtr(std::string const *str){
    
    std::cout << *str << std::endl;
}

void byRef(std::string &str){
    
    str += " and ponies";
}

// void    byConstRef(const std::string &str){ // tanto faz colocar o "const" antes ou depois (é uma questão de gosto)
void    byConstRef(std::string const &str){
    std::cout << str << std::endl;
}

int main(){
    
    std::string str = "HI THIS IS BRAIN";
    
    std::string *stringPTR = &str;
    std::string &stringREF = str;

// endereços
    std::cout << "Address str: " << &str << std::endl;
    std::cout << "Address stringPTR: " << &stringPTR << std::endl;
    std::cout << "Address stringREF: " << &stringREF << std::endl;

std::cout << std::endl;
// conteúdos

    std::cout << "Value str: " << str << std::endl;
    std::cout << "Value stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value stringREF: " << stringREF << std::endl;

    return (0);
}