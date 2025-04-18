/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:44:06 by asalo             #+#    #+#             */
/*   Updated: 2025/04/18 20:20:27 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &src) {
	(void)src; // no members => src unused.
}

Serializer &Serializer::operator=(const Serializer &src) {
    (void)src;
	return *this;
}

Serializer::~Serializer() {}

// reinterpret_cast specifically designed for casting between unrelated types
uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Serializer::Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Serializer::Data*>(raw);
}
