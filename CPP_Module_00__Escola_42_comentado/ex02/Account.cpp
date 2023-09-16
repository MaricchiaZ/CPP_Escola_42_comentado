/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:07:00 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/24 15:45:26 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <string>
#include <cstdio>
#include <locale>
#include <iostream>
#include <ctime>

// inicializando as variáveis
	int	Account::_nbAccounts = 0;
	int	Account::_totalAmount = 0;
	int	Account::_totalNbDeposits = 0;
	int	Account::_totalNbWithdrawals = 0;
    int	_accountIndex = 0;
	int _amount = 0;
	int _nbDeposits = 0;
	int _nbWithdrawals = 0;

// constructor
Account::Account(int initial_deposit): _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0){
	// constructor que recebe um argumento - depósito inicial
	// e inicializa as variáveis com os valores passados nos parentes
        
	Account::_nbAccounts++; // número de contas aumenta uma unidade
	Account::_totalAmount += initial_deposit; // valor da conta recebe o depósito
	_displayTimestamp(); // Data-hora em que ocorre a operação
    
	// printamos o índice, o amount e avisamos que criamos a conta
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";" << "created" << std::endl;
}

// destructor
Account::~Account(void){

	_displayTimestamp(); // Data-hora em que ocorre a operação

	// // printamos o índice, o amount e avisamos que fechamos a conta
	std::cout << "index:" << this->_accountIndex << ";amount:" << checkAmount() << ";closed" << std::endl;
	_nbAccounts--; // número de contas perde uma unidade
	_totalAmount -= checkAmount(); // perdemos o total dessa conta, então o valor total é subtraído no valor dessa conta
}

// getters - acessam as variáveis e retornam o valor delas
int	Account::getNbAccounts( void ){
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void ){
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void ){
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ){
	return (Account::_totalNbWithdrawals);
}

// função de depositar
void	Account::makeDeposit(int deposit) {
    
	const int	p_amount = this->_amount; //salvamos o valor que tem na conta
    
	_displayTimestamp();  // Data-hora em que ocorre a operação

	this->_amount += deposit; // acrescentamos o depósito feito nessa conta
	Account::_totalAmount += deposit; // acrescentamos o depósito feito no valot total do controle
	this->_nbDeposits++; // número de depósitos feitos nessa conta ganha uma unidade
	Account::_totalNbDeposits++; // número de depósitos feitos no total ganha uma unidade

// printamos as infos dessa transferência
	std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";deposit:"
    << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

// função que realizar um saque no valor de withdrawal, se possível
bool	Account::makeWithdrawal(int withdrawal) {
    
	_displayTimestamp(); // Data-hora em que ocorre a operação
    
	if (_amount - withdrawal < 0) { // confere se o valor sacado existe na conta, se é menor que o saldo que a pessoa tem
	// se não for possível sacar
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl; // informa 
		// que o saque foi recusado
		return (false); // booleano retorna falso
	}

	this->_nbWithdrawals++; // atualiza o número de saques feito pela conta
	_totalNbWithdrawals++; // atualiza o número total de saques feitos
	this->_amount -= withdrawal; // subtrai o valor total dessa conta
	_totalAmount -= withdrawal; // subtrai o valor do saque, do valor total
    
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << checkAmount() + withdrawal
	<< ";withdrawal:" << withdrawal << ";amount:" << checkAmount() << ";nb_withdrawals:" << this->_nbWithdrawals
	<< std::endl; // avisa o saque
	return (true); // retorna que foi possível
}

// função que checa o valor total
int	Account::checkAmount( void ) const{ 
	return (Account::_amount);
}

// função que expõe o status da conta, quantos depósitos, quantos saques....
void	Account::displayStatus(void) const {
    
	_displayTimestamp(); // Data-hora em que ocorre a operação
    
	std::cout << "index:" << this->_accountIndex << ";amount:" << checkAmount()
	<< ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals
	<< std::endl; // printa o status da conta
}


// função que expõe o status total, quantos depósitos todas as contas fizeram, quantos saques....
void	Account::displayAccountsInfos(void) {
    
	Account::_displayTimestamp(); // Data-hora em que ocorre a operação
    
	std::cout << "accounts:" << Account::getNbAccounts() << ";"
	<< "total:" << Account::getTotalAmount() << ";"
	<< "deposits:" << Account::getNbDeposits() << ";"
	<< "withdrawals:" << Account::getNbWithdrawals()
	<< std::endl; // printa os status...
}

// função que retorna o tempo em que ocorre a transição
void	Account::_displayTimestamp(void) {
    
	const std::time_t	time = std::time(NULL); // vai receber uma hora/data
	const std::string	format = "%Y%m%d_%H%M%S"; // nesse formato
	char				timestamp[16]; // YYYYmmdd_HHMMSS
    
	std::strftime(timestamp, 16, format.c_str(), std::localtime(&time)); // salva a data e hora nlocal (td::localtime(&time)) na
	// string timestamp de 16 caracteres 
	std::cout << "[" << timestamp << "] "; // printa as chaves, a data_hora e o espaço depois
}


// Como testar o projeto:
// ./tests | awk '{$1=""; print $0}' >> a 
// awk '{$1=""; print $0}' log.log >> b
// diff a b >> c
