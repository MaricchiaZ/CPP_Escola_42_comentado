/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstream1.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:43:40 by maclara-          #+#    #+#             */
/*   Updated: 2023/06/18 12:57:14 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(){
    std::ifstream ifs("numbers"); // associamos um objeto std::ifstream chamado ifs  ao arquivo "numbers", 
    // usando o construtor
    // lê linha a linha, salvando as linhas em um buffer temporário que é reutilizado a cada linha 
    unsigned int    dst; //  variáveis usadas para armazenar os dados lidos do arquivo
    unsigned int    dst2;
    ifs >> dst >> dst2; // lê dois valores do arquivo "numbers" e os armazena nas variáveis dst e dst2, respectivamente.
 
    std::cout << dst << " " << dst2 << std::endl;
    ifs.close(); //  é chamada para fechar o arquivo ifs.

    // -------------------------------------------------

    std::ofstream ofs("test.out"); // um objeto std::ofstream chamado ofs é criado e associado
    //  ao arquivo "test out" usando o construtor.

    ofs << "i like ponies a whole damn lot" << std::endl; //  grava a string "i like ponies a whole damn lot"
    //  no arquivo "test out".
    ofs.close();
}

// g++ filestram1.cpp

/*
 ./a.out
1001 1002


~/Trabalhos/MC_42/CPP_Module_01__Escola_42/ex00/estudo/filestream ❯ cat numbers 
1001
1002
1003
1004

~/Trabalhos/MC_42/CPP_Module_01__Escola_42/ex00/estudo/filestream ❯ cat test.out
i like ponies a whole damn lot

*/
