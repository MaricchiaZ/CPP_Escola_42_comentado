/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:47:16 by maclara-          #+#    #+#             */
/*   Updated: 2023/06/14 20:59:37 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class Contact {
    
public:

    void	setFirstName(std::string s);
    void	setLastName(std::string s);
    void	setNickname(std::string s);
    void	setPhoneNumber(std::string s);
    void	setDarkestSecret(std::string s);

    std::string	getFirstName(void);
    std::string	getLastName(void);
    std::string	getNickname(void);
    std::string	getPhoneNumber(void);
    std::string	getDarkestSecret(void);

    Contact();
    ~Contact();

private:

    std::string first_name;
    std::string last_name;
    std::string	nickname;
    std::string	phone_number;
	std::string	darkest_secret;
        
};

#endif