/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:25:30 by asalo             #+#    #+#             */
/*   Updated: 2025/04/19 12:00:00 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <cstdlib> 

template <typename T>
class Array {
    private:
        T*      _array;
        uint    _array_size;

    public:
        Array();
        ~Array();

        Array(unsigned int n);
        // explicit Array(unsigned int n);
        Array(const Array& src);
        Array& operator=(const Array& src);


        T& operator[](uint size);
        const T& operator[](unsigned int index) const;
        uint size() const;

        class OutOfBoundsException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

#include "Array.tpp"

#endif