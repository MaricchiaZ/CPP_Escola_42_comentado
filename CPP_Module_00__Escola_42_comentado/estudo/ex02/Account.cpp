/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:07:00 by maclara-          #+#    #+#             */
/*   Updated: 2023/06/22 17:52:56 by maclara-         ###   ########.fr       */
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

// constructor e destructor 
Account::Account(int initial_deposit):
	_accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0){
        
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	_displayTimestamp(); // Data-hora em que ocorre a operação
    
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "created" << std::endl;
}

Account::~Account(void){

	_displayTimestamp(); // Data-hora em que ocorre a operação
    
	std::cout << "index:" << this->_accountIndex << ";amount:" << checkAmount() << ";closed" << std::endl;
	_nbAccounts--;
	_totalAmount -= checkAmount();
}

// getters
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

// funções membros

void	Account::makeDeposit(int deposit) {
    
	const int	p_amount = this->_amount;
    
	_displayTimestamp();  // Data-hora em que ocorre a operação

	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;

	std::cout << "index:" << _accountIndex << ";" << "p_amount:" << p_amount << ";" << "deposit:"
    << deposit << ";" << "amount:" << _amount << ";" << "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
    
	_displayTimestamp(); // Data-hora em que ocorre a operação
    
	if (_amount - withdrawal < 0) {
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << _amount
		<< ";withdrawal:refused" << std::endl;
		return (false);
	}

	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
    
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << checkAmount() + withdrawal
	<< ";withdrawal:" << withdrawal << ";amount:" << checkAmount() << ";nb_withdrawals:" << this->_nbWithdrawals
	<< std::endl;
	return (true);
}

int	Account::checkAmount( void ) const{
	return (Account::_amount);
}

void	Account::displayStatus(void) const {
    
	_displayTimestamp(); // Data-hora em que ocorre a operação
    
	std::cout << "index:" << this->_accountIndex << ";amount:" << checkAmount()
	<< ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals
	<< std::endl;
}


// funções não membros
void	Account::displayAccountsInfos(void) {
    
	Account::_displayTimestamp(); // Data-hora em que ocorre a operação
    
	std::cout << "accounts:" << Account::getNbAccounts() << ";"
	<< "total:" << Account::getTotalAmount() << ";"
	<< "deposits:" << Account::getNbDeposits() << ";"
	<< "withdrawals:" << Account::getNbWithdrawals()
	<< std::endl;
}

void	Account::_displayTimestamp(void) {
    
	const std::time_t	time = std::time(NULL);
	const std::string	format = "%Y%m%d_%H%M%S";
	char				timestamp[16]; // YYYYmmdd_HHMMSS
    
	std::strftime(timestamp, 16, format.c_str(), std::localtime(&time)); // salva a data e hora na strftime
	std::cout << "[" << timestamp << "] "; // printa as chaves, a data_hora e o espaço depois
}


// Como testar o projeto:
// ./tests | awk '{$1=""; print $0}' >> a 
// awk '{$1=""; print $0}' log.log >> b
// diff a b >> c