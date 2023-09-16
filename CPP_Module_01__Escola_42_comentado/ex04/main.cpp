/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:08:30 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/24 21:53:10 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char** argv){

	if (argc != 4){ 
        std::cout << "Error: write ->: ./file <filename> <String> <remplaceString>" << std::endl;
        return 1;
    }

    std::string filename = argv[1]; // armazenamos os argvs
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    std::string buff; //  variável usada para armazenar os dados lidos do arquivo
    std::string::size_type	n;

// file_in
	std::ifstream file_in;
	file_in.open(argv[1], std::ifstream::in); // abrimos o arquivo
	if (file_in.fail()) {
		std::cerr << "Failed to open " << argv[1] << " for reading" << std::endl;
		return 1;
	}
    // file_out
    std::string const	file_out_name = filename += ".replace"; // criamos o file.out
    std::ofstream file_out;
    file_out.open(file_out_name.c_str(), std::ofstream::out);; //criado e associado
    //  ao arquivo "filename.replace" usando o construtor.
		if (file_out.fail()) {
		std::cout << "Error creating file" << std::endl;
		return (0);
        }
    
	std::cout << "Done: replacing every occurrence of '" << s1 << "' with '" << s2 << "'" << std::endl;
	// avisamos q iremos trocar as ocorrências s1 pelas s2

	while (getline(file_in, buff)) { // lemos de linha em linha
		while ((n = buff.find(s1)) != std::string::npos) { // procuramos s1 na linha que pegamos
			file_out << buff.substr(0, n); // estraímos do buffer da posição 0 até n-1
			buff.erase(0, n + s1.length()); // trocamos s1
			file_out << s2; // por s2
		}
		file_out << buff << std::endl; //passamos  isso pro file.out
	}
    file_in.close(); //  é chamada para fechar o arquivo file.
    file_out.close(); //  é chamada para fechar o arquivo file_out.
	return 0;
}

/*
make
./file file_in "horta da vovó" "mercado da vila"
*/
