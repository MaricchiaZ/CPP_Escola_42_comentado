/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heritage3.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:12:47 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/10 11:27:41 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ISSO É SÓ UM ESQUEMA DE EXEMPLO 

class Quadruped{ // Can access name, run() and legs
    
public:
    void run(); // acessível a qualquer um

protected:
    Leg legs[4]; // acessível por um objeto da classe Quadruped ou por uma classe que herda de Quadruped (classe derivada de quadruped))    
    
private:
    std::string _name; // acessível apenas por um objeto da classe Quadruped
};

class Dog : public Quadruped{ //Pode acessar a função run() e legs - (porque a função run() é pública e legs é protected)
    
};

int main() // Pode acessar SOMENTE a função run() - porque é pública
{
    
}
