/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:41:46 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/08 11:40:48 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
#define EASYFIND_H

# include <iostream>
# include <vector>
# include <algorithm>
# include <iterator>

class NotFound : public std::exception
{
    public:
        const char* what() const throw(){
            return ("Infortunatly dosn't exist in this container\n");
        }
};

template <typename T>
typename T::iterator easyfind(T& intContainer, int val) {
    typename T::iterator iter = std::find(intContainer.begin(), intContainer.end(), val);
    if (iter == intContainer.end()){
        throw NotFound();
    }
        
	return iter;
}

#endif
