/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:36:06 by maclara-          #+#    #+#             */
/*   Updated: 2023/07/10 11:11:22 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{

  Zombie* zumbiew = newZombie("zomby");
  zumbiew->announce();
  Zombie* zii = newZombie("zzuummb");
  zii->announce();
  randomChump("szhumbzs");

  delete zumbiew; // similar ao free() em C
  delete zii; // similar ao free() em C
}