/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:47:49 by asalo             #+#    #+#             */
/*   Updated: 2025/04/21 13:36:35 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"
#include <iostream>

template <typename T>
Array<T>::Array() : _array(NULL), _array_size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array_size(n) {
    if (n == 0) {
        _array = NULL;
    } else {
        _array = new T[n]; // Value-init (zeroing ints)
    }
}

template <typename T>
Array<T>::Array(const Array<T>& src) : _array(NULL), _array_size(0) {
    *this = src;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& src) {
    if (this != &src) {
        delete[] _array;
        _array_size = src._array_size;
        if (_array_size == 0) {
            _array = NULL;
        } else {
            _array = new T[_array_size];
            for (unsigned int i = 0; i < _array_size; ++i) {
                _array[i] = src._array[i];
            }
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] _array;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _array_size) {
        throw OutOfBoundsException();
    }
    return _array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _array_size) {
        throw OutOfBoundsException();
    }
    return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _array_size;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
    return "Index is out of bounds";
}

#endif