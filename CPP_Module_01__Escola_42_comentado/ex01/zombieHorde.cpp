/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:22:42 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/10 10:28:13 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Zombie.hpp"

Zombie*	zombieHorde(int n, std::string name) {
	Zombie*	horde = NULL;

	if (n <= 0) {
		return horde;
	}
	horde = new Zombie[n]; // similar ao malloc em C
	for (int i = 0; i < n; i++) {
		horde[i].setZombie(name);
	}

	return horde;
}