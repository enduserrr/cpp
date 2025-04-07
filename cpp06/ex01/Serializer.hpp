/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:33:09 by asalo             #+#    #+#             */
/*   Updated: 2025/04/07 18:55:09 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <stdint.h>

class Serializer {
    private:
        Serializer();
        Serializer(Serializer const& src);
        Serializer& operator=(Serializer const& src);
        ~Serializer();
    public:
        typedef struct Data
        {
            std::string s1;
            int n;
            std::string s2;
        } Data;
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif
