/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref2.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:17:37 by maclara-          #+#    #+#             */
/*   Updated: 2023/06/18 11:28:17 by maclara-         ###   ########.fr       */
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
    
    std::string str = "I like butterflies";

    std::cout << str << std::endl;
    byPtr(&str);
    byConstPtr(&str);

    str = "I like otters";
    std::cout << str << std::endl;
    byRef(str);
    byConstRef(str);

    return (0);
}