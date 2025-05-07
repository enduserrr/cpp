#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {
    private:
        T*      _array;
        uint    _array_size;

    public:
        Array();
        ~Array();

        Array(unsigned int n);
        Array(const Array& src);
        Array& operator=(const Array& src);


        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
        uint size() const;

        class OutOfBoundsException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

#include "Array.tpp"

#endif