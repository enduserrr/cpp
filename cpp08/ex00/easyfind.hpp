/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 11:57:17 by asalo             #+#    #+#             */
/*   Updated: 2025/04/26 14:36:31 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>    // std::find
#include <iterator>     // Container iterators
#include <exception>
#include <stdexcept>

class NotFoundException : public std::exception {
    public:
        virtual const char* what() const noexcept override {
            return "Element not found in the container";
        }
};

template <typename T>
typename T::iterator easyFind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw NotFoundException();
    }
    return it;
};

#endif