/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:01:48 by asalo             #+#    #+#             */
/*   Updated: 2025/04/17 09:16:56 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef WHATEVER_HPP
#define WHATEBER_HPP

#include <iostream>

template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
const T& min(const T& a, const T& b) {
    return (b <= a) ? b : a; // what'd change after swapping vars around ':'?
}

// Template func to return the larger of two values
// (if equal, returns the second one which is b)
template <typename T>
const T& max(const T& a, const T& b) {
    return (b >= a) ? b : a;
}

#endif