/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:44:06 by asalo             #+#    #+#             */
/*   Updated: 2025/04/07 18:53:34 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &src) {
	*this = src;
}

Serializer &Serializer::operator=(const Serializer &src) {
	if(this != &src) {
		*this = src;
	}
	return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Serializer::Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Serializer::Data*>(raw);
}
