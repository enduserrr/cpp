#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& src) {
    *this = src;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& src) {
    if (this != &src) {
        std::stack<T>::operator=(src);
    }
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin(); // STL container member func returning iterator
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return this->c.end(); // STL container member func returning iterator
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
    return this->c.end();
}

#endif