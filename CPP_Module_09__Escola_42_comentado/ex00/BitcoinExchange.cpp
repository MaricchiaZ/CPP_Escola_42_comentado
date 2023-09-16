/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:00:25 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/22 19:32:14 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// construtor
BitcoinExchange::BitcoinExchange() {
    std::cout << std::setw(15) << "[BitcoinExchange] "<< "create!!!" << std::endl; // mudar essa linha
    this->base.open("data.csv"); // abre o arquivo com as cotações
    if (this->base.is_open()) // se abrir o arquivo funcionar
        MakeMap(); // criamos o conteiner map com as cotações e as datas
    else{
        std::cout << "ERROR: Cannot open file" << std::endl; // avisamos o erro
        exit(1); // saímos do programa
    }
}

// destructor
BitcoinExchange::~BitcoinExchange() {
    std::cout << std::setw(15) << "[BitcoinExchange] " << "delete!!" << std::endl;  // mudar essa linha
    this->base.close(); // fechamos o arquivo com as cotações
}

// Cópia do constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref) {
    *this = ref;
    std::cout << std::setw(15) << "[BitcoinExchange] " << "copy!!" << std::endl;  // mudar essa linha
}

// Cópia por atribuição
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &ref) {
    std::cout << std::setw(15) << "[BitcoinExchange] " << "operator=!!" << std::endl;  // mudar essa linha
    this->standard = ref.standard;
    return (*this);
}

// Verifica se é um ano bissexto
bool BitcoinExchange::CheckLeapYear(int year) {
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
} //  Um ano bissexto é aquele que é divisível por 4, com exceção dos anos que são divisíveis por 100, 
// a menos que também sejam divisíveis por 400. A função retorna true se o ano for bissexto e false caso contrário.
// A função retorna true se qualquer uma das duas primeiras condições (divisível por 4 e não divisível por 100) for 
// verdadeira, ou se a terceira condição (divisível por 400) for verdadeira. Caso contrário, retorna false, indicando 
// que o ano não é bissexto.

// verifica se a data é válida levando em consideração os meses, dias e a possibilidade de anos bissextos.
bool BitcoinExchange::CheckValidDate(int year, int month, int day) {
    // verificações gerais
    if (month < 1 || month > 12) // os meses só podem ser de 1 a 12
        return false;
    if (day < 1 || day > 31) // os dias só são validos de 1 a 31
        return false;
    // verificações específicas
    if (month == 4 || month == 6 || month == 9 || month == 11) { // Abril, Junho, Setembro e Novembro tem 30 dias
        if (day > 30) 
            return false;
    } else if (month == 2) { // se for fevereiro, confere se é bissexto se tem 29 dias
        if (this->CheckLeapYear(year) && day > 29)
            return false;
        if (!(this->CheckLeapYear(year)) && day > 28) // se não for bissexto, confere se tem 28 dias
            return false;
    }
    return true;
}

// Essa função é usada para dividir uma string em substrings com base em um delimitador e 
// armazená-las em uma fila (queue) de strings.
std::queue<std::string> BitcoinExchange::Split(std::string input, char delimiter) {
    std::queue<std::string> result; // uma fila (queue) de strings chamada result é criada para armazenar as substrings após a divisão.
    std::stringstream ss(input); // Uma instância de std::stringstream chamada ss é criada a partir da string de entrada input. 
    // Isso permite que você itere por cada parte da string usando o delimitador.
    std::string tmp;

    while (getline(ss, tmp, delimiter)) // a função utiliza a função getline(ss, tmp, delimiter) para extrair partes da string input.
    //  A função getline lê caracteres da stream até encontrar o delimitador ou atingir o final da stream. A parte lida é armazenada 
    // na variável tmp.
        result.push(tmp); // A parte lida é então inserida na fila result usando o método push.
    return result; // A função retorna a fila result contendo todas as substrings separadas.
}

// Essa função é usada para converter um valor de tipo double em uma string.
std::string BitcoinExchange::DoubleToString(double value) {
    std::ostringstream o;
    if (!(o << value))
        return "";
    return o.str();
} // _____________________________________________________________ CONFERIR SE USAMOS _______


// Essa função é usada para preencher um mapa chamado standard com valores lidos de um fluxo de entrada base.
void BitcoinExchange::MakeMap() {
    std::string key;
    std::cout << "=========Make Map=========" << std::endl; // MUDAR ESSA FRASE
    while (getline(this->base, key, ',')) { //vai lendo linhas do fluxo de entrada base e processando-as até 
    // que não haja mais linhas para ler.
        if (key == "date") { // Se a chave lida for "date", a função lê a linha inteira e continua para a próxima iteração do loop. 
        // Isso é feito para pular a linha que contém a data, uma vez que essa linha não contém um valor numérico que desejamos 
        // armazenar no mapa.
            getline(this->base, key);
            continue;
        }
        // E se a chave não for "date", a função lê a linha inteira usando getline(this->base, val). 
        // Isso obtém o valor associado à chave.
        std::string val;
        getline(this->base, val);
        this->standard[key] = atof(val.c_str()); // O valor obtido é então convertido em um número de ponto
        //  flutuante usando atof(val.c_str()), e esse valor é armazenado no mapa standard usando a chave como índice.
    }
}

// MakeChange é chamado com frequência, então a linha é colocada na área estática.
//  Prossiguimos na direção de referenciá-lo
int BitcoinExchange::ValidationCheck(
    std::string &line_,
    std::queue<std::string> &_strs) { //Utiliza uma desreferência para guardar depois de limpar
    std::queue<std::string> string_s;
    std::queue<std::string> datetime_str;
    double check;
    int i = 0;
    int pipe_cnt = 0;
    int hipen_cnt = 0;
    int dot_cnt = 0; // Pode ser 0 ou 1
    int sp_cnt = 0;  // 2 ou erro incondicional

    while (line_[i]) {
        if (pipe_cnt == 0 && line_[i] == '-') // Comparação de | com um hífen normal -
            hipen_cnt++;
        else if (line_[i] == '|')
            pipe_cnt++;
        else if ((line_[i] < 48 || line_[i] > 57) && line_[i] != 32 &&
                 line_[i] != 46 && line_[i] != 45) //++98 space!
        {
            std::cout << "Error: bad input => " << line_ << std::endl;
            return 0;
        } else if (line_[i] == 32)
            sp_cnt++;
        else if (line_[i] == 46) {
            dot_cnt++;
            if (pipe_cnt == 0) // Encontrando um ponto sem um pipe ////??????
            {
                std::cout << "Error: bad input => " << line_ << std::endl;
                return 0;
            }
        } else if (pipe_cnt && line_[i] == '-') // para o distinguir dO HIFEN
        {
            std::cout << "Error: not a positive number." << std::endl;
            return 0;
        }
        i++;
    }
    if (pipe_cnt != 1 || hipen_cnt != 2 || sp_cnt != 2 || dot_cnt > 1){
        std::cout << "Error: bad input => " << line_ << std::endl;
        return 0;
    }

    string_s = this->Split(line_, '|');
    int datetime_len = string_s.front().size(); // tamanho antes
    if (string_s.size() != 2 || string_s.front()[datetime_len - 1] != ' ' ||
        string_s.back()[0] != ' ') {
        std::cout << "Error: bad input => " << line_ << std::endl;
        return 0;
    }
    string_s.front().erase(datetime_len - 1, 1);
    datetime_len = string_s.front().size(); // Reatribuição
    string_s.back().erase(0, 1);
    datetime_str = this->Split(string_s.front(), '-');

    if (datetime_str.size() != 3 ||
        (string_s.back().size() == 1 &&
         dot_cnt == 1)) // if (datetime_str.size()!=3) ++>> //  Se ao menos o "." estivesse a aparecer
    {
        std::cout << "Error: bad input => " << line_ << std::endl;
        return 0;
    }

    // Tratamento de casos com números a seguir a 2012-01-012|
    int t1 = atoi(datetime_str.front().c_str());
    datetime_str.pop();
    int t2 = atoi(datetime_str.front().c_str());
    datetime_str.pop();
    int t3 = atoi(datetime_str.front().c_str());
    datetime_str.pop();

    // Validar cada data
    if (this->CheckValidDate(t1, t2, t3) == false) //  ou || datetime_str.size()!=3)
    {
        std::cout << "Error: bad input => " << line_ << std::endl;
        return 0;
    }
    std::cout.precision(19);
    check = atof(string_s.back().c_str());
    if (check > 1000.0) //(check > 2147483647.0)
    {
        std::cout << "Error: too large a number." << std::endl;
        return 0;
    }
    if (check < 0.0) {
        std::cout << "Error: not a positive number." << std::endl;
        return 0;
    }
    std::cout.precision(7); // Inicializar a precisão 6 é a predefinição, mas fazemo-lo para melhorar as imagens
    _strs.push(string_s.front());
    _strs.push(string_s.back());
    return 1;
}

// Esa função é responsável por realizar a troca de valores entre diferentes moedas, com base em um arquivo de entrada, 
// utilizando taxas de conversão previamente definidas em um mapa.
void BitcoinExchange::MakeExchange(char *_argv) {
    bool flag = false; // começamos declarando variáveis como flag (para controlar o estado de leitura)
    std::string line; // line (para armazenar cada linha lida do arquivo)
    std::map<std::string, double>::iterator it; // it (um iterator para percorrer o mapa standard)
    float _val; // e _val (para armazenar o valor numérico da conversão)

    // A função abre o arquivo especificado pelo argumento _argv usando this->myfile.open(_argv). 
    // Se o arquivo estiver aberto com sucesso, a função entra em um loop para ler cada linha do arquivo usando getline.
    this->myfile.open(_argv);
    if (this->myfile.is_open()) {
        std::cout << std::string(80, '-') << std::endl;
        std::cout << "File Opened: the conversion has begun ..." << std::endl << std::endl;
        
        while (getline(this->myfile, line)) { // date | value
            std::queue<std::string> _strs;
            // A primeira parte do loop trata a linha "date | value". Se essa linha for encontrada, verifica-se se 
            //a flag já está ativada. Se estiver, isso significa que essa linha apareceu mais de uma vez no arquivo, 
            // o que é considerado um erro. A flag é definida como verdadeira para indicar que a linha foi encontrada.
            if (line == "date | value") {
                if (flag == true) {
                    std::cout << "Error: bad input => " << line << std::endl;
                }
                flag = true;
                continue;
            }
            
            // Se a linha não for "date | value", a função prossegue com a leitura da próxima linha. Primeiro, 
            // a linha é validada usando a função ValidationCheck. Se a validação falhar (retorno 0), a linha 
            // é ignorada e a próxima iteração do loop começa.
            flag = true;
            if (this->ValidationCheck(line, _strs) == 0)
                continue;

            // Se a validação passar, a função verifica se o valor na primeira posição da fila _strs (que foi preenchida
            //  pela função ValidationCheck) é menor do que a primeira chave no mapa standard. Se for, isso indica que 
            // não há dados padrão para essa data e um erro é exibido.
            if (_strs.front() < (this->standard).begin()->first) {
                std::cout << "Error: No Standard Data. => " << _strs.front() << std::endl;
                continue;
            }

            // Se não houver erro até agora, a função procura no mapa standard o valor correspondente à data na 
            // fila _strs usando lower_bound. O valor numérico do segundo elemento na fila _strs (o valor da moeda) é 
            // convertido em ponto flutuante usando atof.
            it = (this->standard).lower_bound(_strs.front());
            _val = atof(_strs.back().c_str());

            // Se a data estiver no mapa standard, a função exibe a conversão da moeda para a moeda padrão multiplicando
            //  o valor do mapa pelo valor da moeda. Se a data não estiver no mapa, a função pega a entrada anterior
            //  usando --it (pois lower_bound pode retornar o próximo elemento) e realiza a mesma operação de conversão.
            if ((this->standard).find(_strs.front()) != (this->standard).end()) {
                std::cout << _strs.front() << " => " << _strs.back() << " = " << (it->second) * _val << std::endl;
            }
            else {
                // validação se a data for futura em relação a última do mapa
                if (_strs.front() > (this->standard).rbegin()->first)
                    std::cout << "Error: No Standard Data. Future data. => " << _strs.front() << std::endl;
                else
                    std::cout << _strs.front() << " => " << _strs.back() << " = " << ((--it)->second) * _val << std::endl;
            }
        }
        this->myfile.close(); // A função fecha o arquivo após terminar de ler as linhas.
        std::cout << std::string(80, '-') << std::endl;
    }
    else {
        std::cout << "ERROR: file does not opened." << std::endl; // avisamos que o arquivo n foi aberto corretamente 
    }
}
