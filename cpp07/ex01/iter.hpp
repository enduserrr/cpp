#ifndef ITER_HPP
#define ITER_HPP

#include <string>

template <typename T, typename F>
void iter(T* array, size_t len, F function) {
    for (size_t i = 0; i < len; i++)
        function(array[i]);
}

#endif