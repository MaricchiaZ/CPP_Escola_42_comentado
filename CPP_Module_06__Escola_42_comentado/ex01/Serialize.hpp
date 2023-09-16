/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:30:55 by maclara-          #+#    #+#             */
/*   Updated: 2023/08/07 16:04:23 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

#include "Data.hpp" 

// Pega num ponteiro e converte-o para o tipo inteiro sem sinal uintptr_t.
uintptr_t serialize(Data* ptr) {
  return (reinterpret_cast<uintptr_t>(ptr));
}

// Recebe um parâmetro inteiro sem sinal e converte-o num ponteiro para Data.
Data* deserialize(uintptr_t raw) {
  return reinterpret_cast<Data*>(raw);
}

#endif
