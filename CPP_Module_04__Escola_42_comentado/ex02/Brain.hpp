/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:04:09 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/27 07:47:36 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <sstream>

class Brain {

public:
    Brain(void);
    ~Brain(void);

    Brain(const Brain &src);
    Brain &operator=(const Brain &src);

    void setIdea(int i, std::string idea);
    std::string getIdea(int i) const;

private:
    std::string ideas[100];
};

#endif
