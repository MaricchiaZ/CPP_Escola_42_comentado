/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 12:02:31 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/24 09:15:13 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Megaphone{ // Definição de uma classe chamada Megafone

public:

    std::string msg; // No C++, o tipo string faz parte do namespace std e não existe fora dele. Portanto, 
    // é necessário usar std::string para se referir ao tipo string da biblioteca padrão.
    
    Megaphone(void); // Construtor
    ~Megaphone(void); // Destrutor
    
    void big_sound(char *mini_sound);
}; // esses ; indicam o fim da definição de classe

// Construtor
Megaphone::Megaphone(void){ // quando o construtor é chamado
    Megaphone::msg = "* LOUD AND UNBEARABLE FEEDBACK NOISE *"; // atribuímos a frase "LOUD ..." à variável msg da classe Megafone
    return;
}

// Destrutor
Megaphone::~Megaphone(void){ // quando o destrutor é chamado, não fazemos nada, não tem nenhuma atividade descrita dentro dele
    return;
}

void    Megaphone::big_sound(char *mini_sound){ // Aqui vamos definir o que faz a função big_sound da classe megafone
    int i = 0;
    while(mini_sound[i]){ // enquanto houver caractere na string mini_sound
        if (mini_sound[i] >= 'a' && mini_sound[i] <= 'z') // se for de 'a' a 'z'
            std::cout << (char)(mini_sound[i] - 32); // transformamos em maiúscula e imprimimos no terminal
        else
            std::cout << mini_sound[i]; // senão, apenas imprimimos no terminal
        i++;
    }
}

int main(int argc, char **argv) // nossa main recebe argc e argv
{
    Megaphone mega; // declaramos um objeto mega da classe Megaphone - NESSE MOMENTO O CONSTRUCTOR É CHAMADO
    int i;

    if (argc == 1){ // se tivermos apenas um argumento, 
        std::cout << mega.msg << std::endl; // colocamos no terminal a string 'msg' do objeto 'mega'
        return 1;
    }
    i = 1; // avançamos para o primeiro argumento depois do a.out
    while(argv[i]){ // enquanto tivermos argumentos para tratar
        mega.big_sound(argv[i]); //aplicamos a função big_soundo do objeto mega sobre o argumento
        std::cout << std::endl; // damos uma quebra de linha
        i++; // partimos para o próximo argumento
    }
    return 0;
}
