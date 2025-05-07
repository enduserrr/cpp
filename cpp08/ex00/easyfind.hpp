#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>    // std::find (STL algo)
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