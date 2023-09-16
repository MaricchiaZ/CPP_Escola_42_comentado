/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:46:17 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/24 14:35:48 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){ // Construtor
    this->nbr_contact = 0; // de início atribuimos o valor de 0 para o número de contatos
    this->index = 0; // e zero para o índice
    return ;
}

PhoneBook::~PhoneBook(void){ // Destrutor sai sem fazer mais nenhuma ação
    return ;
}

// função para adicionar um contato à lista de contatos
void    PhoneBook::add(void){

    Contact new_contact; // criamos um objeto contat pra ser um temporário enquanto cadastramos os dados nele
    std::string temp_buffer;
    
    std::cin.ignore(); // a função ignore do objeto std::cin descarta qualquer caractere pendente no buffer de entrada.
    std::cout << "Add Contact infos" << std::endl; // avisamos que estamos coletando as infos do usuário
    
    // pegamos o First Name e salvamos no objeto temporário new_contact
    temp_buffer = ""; // limpamos o buffer
    std::cout << "First name: "; // colocamos no terminal que queremos a info First Name
    std::cin >> temp_buffer; // salvamos o que a pessa escreveu no temp_buffer
    if (temp_buffer == "") { // se estiver vazio, 
        std::cout << "Invalid input" << std::endl << std::endl; // avisamos que o input é inválido
        return ; // saímos da função add
    }
    new_contact.setFirstName(temp_buffer); // se tudo estiver certo passamos o First Name para o new_contact

    // pegamos Last Name e salvamos em new_contact
    temp_buffer = ""; // limpamos o buffer
    std::cout << "Last Name: ";  // colocamos no terminal que queremos a info Last Name
    std::cin >> temp_buffer; // salvamos o que a pessa escreveu no temp_buffer
    if (temp_buffer == "") { // se estiver vazio, 
        std::cout << "Invalid input" << std::endl << std::endl; // avisamos que o input é inválido
        return ; // saímos da função add
    }
    new_contact.setLastName(temp_buffer); // se tudo estiver certo passamos o Last Name para o new_contact
    
    // pegamos o Nickname  e salvamos em new_contact
    temp_buffer = ""; // limpamos o buffer
    std::cout << "Nickname: ";  // colocamos no terminal que queremos a info Nickname
    std::cin >> temp_buffer; // salvamos o que a pessa escreveu no temp_buffer
    if (temp_buffer == "") { // se estiver vazio, 
        std::cout << "Invalid input" << std::endl << std::endl;  // avisamos que o input é inválido
        return ; // saímos da função add
    }
    new_contact.setNickname(temp_buffer); // se tudo estiver certo passamos o Nickname para o new_contact

    // pegamos o Phone number e salvamos em new_contact
    temp_buffer = ""; // limpamos o buffer
    std::cout << "Phone number: "; // colocamos no terminal que queremos a info Phone Number
    std::cin >> temp_buffer;// salvamos o que a pessa escreveu no temp_buffer
	if (temp_buffer == "" || temp_buffer.find_first_not_of("0123456789") != std::string::npos) {// verifica se está vazio OU busca o 
    // primeiro caractere que não pertence ao conjunto de dígitos numéricos "0123456789" e se for diferente de 'std::string::npos' (que
    //  é um valor especial indicando que o caractere não foi encontrado).
		std::cout << "Invalid input" << std::endl << std::endl; // avisamos que o input é inválido
		return ;// saímos da função add
    }
    // verifica se há algum caractere no número de telefone que não seja um dígito de 0 a 9. O método 
    // find_first_not_of é usado para encontrar o primeiro caractere que não faz parte da lista de dígitos fornecida.
    new_contact.setPhoneNumber(temp_buffer); // se tudo estiver certo passamos o Phone Number para o new_contact

    // pegamos o  Darkest secret e salvamos em new_contact
    temp_buffer = ""; // limpamos o buffer
    std::cout << "Darkest secret: "; // colocamos no terminal que queremos a info Segredo
    std::cin >> temp_buffer; // salvamos o que a pessa escreveu no temp_buffer
    if (temp_buffer == "") {  // se estiver vazio, 
        std::cout << "Invalid input" << std::endl << std::endl;   // avisamos que o input é inválido
        return ;// saímos da função add
    }
    new_contact.setDarkestSecret(temp_buffer); // se tudo estiver certo passamos o PDark Secret para o new_contact

    // se deu tudo certo até agora
    list_contacts[this->index] = new_contact; // o array  list_contacts na posição da variável index recebe esse novo contato new_contact
    this->index++; //índice ganha uma unidade
	if (this->nbr_contact < 8) // se o número de contatos ainda não chegou em 8
		this->nbr_contact++; // marcamos que temos mais um contato
	if (this->index == 8) // se o índice atingiu 8 (já temos o número máximo de contatos)
		this->index = 0; // zeramos o índice
	return ;
}


// funcão que busca algum contato na lista
void    PhoneBook::search_contact(void){
    
	std::stringstream str_to_int; // É comum usar objetos std::stringstream para fazer conversões de strings para outros tipos de dados, 
    // como inteiros, floats, etc., e também para criar strings formatadas com base em dados numéricos.
	int	index = -1; // o índice recebe um valor de -1 para não ser nenhum índice existente
    
    std::cout << std::endl; // quebramos uma linha
    std::cout << "|     Index|First Name| Last Name|  Nickname|"<< std::endl; // colocamos o topo da tabela
	for (int i = 0; i < this->nbr_contact; i++) { // enquanto i for menor so que o número de contatos
		this->printInfo(this->list_contacts[i], i); // printamos a info reduzida dos contatos
	}
    std::string	id; // declaramos que vamos usar uma string chamada id
    std::cout << "Insert ID to search (0 - 7): "; // pedimos pra pessoa escolher o id
    std::cin >> id; // salvamos o id na string id
    std::cout << std::endl; // quebramos a linha
    str_to_int << id; // jogamos a string id na string de conversão str_to_int
    str_to_int >> index; // passamos o conteúdo da string str_to_int para o int index
    if (id != "" && id.find_first_not_of("0123456789") && 0 <= index && index < this->nbr_contact) // se id for nulo E só encontrarmos
    // caracteres do 0 ao 9 E índice for maior que 0 e menor do que o número de contatos salvos
        this->printContact(this->list_contacts[index]); // printamos as infos completas do contato escolhidp
    else
        std::cout << "Invalid Input" << std::endl; // caso contrário, avisamos que o input do índice estava errado
}

// função auxiliar para printar os dados completos de um contato escolhido
void	PhoneBook::printContact(Contact contact) {
	std::cout << "First name : " << contact.getFirstName() << std::endl;
	std::cout << "Last name : " << contact.getLastName() << std::endl;
	std::cout << "Nickname : " << contact.getNickname() << std::endl;
	std::cout << "Phone number : " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret : " << contact.getDarkestSecret() << std::endl << std::endl;
}

// função auxiliar para printar os dados completos de um contato escolhido
void	PhoneBook::printInfo(Contact contact, int index) {
	Contact	format = contact; // copiamos os dados do contact para o format (por que iremos modificar esse contato para fazer a 
    // formatação adequada)

	if (format.getFirstName().length() > 10) { // se o tamanho da variável for maior do que 10 caracteres
		format.setFirstName(format.getFirstName().substr(0, 9) + '.'); // fazemos uma substring do caractere 0 ao 9 e adicionamos um ponto no final
	}
	if (format.getLastName().length() > 10) { // se o tamanho da variável for maior do que 10 caracteres
		format.setLastName(format.getLastName().substr(0, 9) + '.'); // fazemos uma substring do caractere 0 ao 9 e adicionamos um ponto no final
	}
	if (format.getNickname().length() > 10) { // se o tamanho da variável for maior do que 10 caracteres
		format.setNickname(format.getNickname().substr(0, 9) + '.'); // fazemos uma substring do caractere 0 ao 9 e adicionamos um ponto no final
	}
	if (format.getPhoneNumber().length() > 10) { // se o tamanho da variável for maior do que 10 caracteres
		format.setPhoneNumber(format.getPhoneNumber().substr(0, 9) + '.'); // fazemos uma substring do caractere 0 ao 9 e adicionamos um ponto no final
	}
	if (format.getDarkestSecret().length() > 10) { // se o tamanho da variável for maior do que 10 caracteres
		format.setDarkestSecret(format.getDarkestSecret().substr(0, 9) + '.'); // fazemos uma substring do caractere 0 ao 9 e adicionamos um ponto no final
	}
	std::cout << "|" << std::setw(10) << index; // A função std::setw(10) é usada para definir uma largura 
    // fixa de 10 caracteres para cada campo exibido. 
    // o manipulador std::setw (set width) define o tamanho do campo de saída.  Ele define o tamanho do campo de saída para o valor especificado, que é 10 no exemplo. 
    // Isso significa que o próximo valor a ser impresso terá um espaço reservado de 10 caracteres no console.
	std::cout << "|" << std::setw(10) << format.getFirstName(); // escrevemos os dados já formatados
	std::cout << "|" << std::setw(10) << format.getLastName();// escrevemos os dados já formatados
	std::cout << "|" << std::setw(10) << format.getNickname() << "|" << std::endl;
}

