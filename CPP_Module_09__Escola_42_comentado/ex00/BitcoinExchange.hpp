/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 11:00:09 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/22 19:32:17 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <queue>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>

class BitcoinExchange {

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &ref);
    BitcoinExchange &operator=(const BitcoinExchange &ref);

    void MakeExchange(char *argv);
    int ValidationCheck(std::string &line, std::queue<std::string> &str);
    bool CheckLeapYear(int year);
    bool CheckValidDate(int year, int month, int day);
    std::queue<std::string> Split(std::string input, char delimiter);
    std::string DoubleToString(double value); // conferir se usamos 

private:
    std::map<std::string, double> standard;
    std::ifstream myfile;
    std::ifstream base;
    void MakeMap();
};

#endif
