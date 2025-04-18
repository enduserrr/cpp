/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:25:30 by asalo             #+#    #+#             */
/*   Updated: 2025/04/18 12:56:50 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ARRAY_HPP
#define ARRA_HPP

#include <iostream>

template <typename T>
class Array {
    private:
        T *arr;
        uint arr_size;

    public:
        Array();
        ~Array();

        Array(unsigned int n);
        Array(Array const &src);
        Array& operator=(Array const &src);


        T& operator[](uint size);
        uint size() const;

        class OutOfBoundsException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

#include "Array.tpp"

#endif