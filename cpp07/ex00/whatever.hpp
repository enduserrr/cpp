/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:01:48 by asalo             #+#    #+#             */
/*   Updated: 2025/04/21 13:21:50 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// If equal, both min & max return the second one
template <typename T>
const T& min(const T& a, const T& b) {
    return (b <= a) ? b : a;
}

template <typename T>
const T& max(const T& a, const T& b) {
    return (b >= a) ? b : a;
}

#endif