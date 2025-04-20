/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 11:57:17 by asalo             #+#    #+#             */
/*   Updated: 2025/04/20 12:09:32 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>    // std::find
#include <iterator>     // Container iterators
#include <exception>    //
#include <stdexcept>    // Is this needed?

class NotFoundException : public std::exception {
    public:
        virtual const char* what() const noexcept override {
            return "Element wasn't found in container";
        }
};

template <typename T>
typename T::iterator easyFind(T& container, int value) {
    // std::find() used for searching the range
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw NotFoundException();
    }
    return it;
};

#endif