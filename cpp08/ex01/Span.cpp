#include "Span.hpp"
#include <algorithm>
#include <climits>


Span::Span() {}

Span::Span(unsigned int N) : _N(N) {}

Span::~Span() {}

Span::Span(const Span& src) {
    *this = src;
}

Span& Span::operator=(const Span& src) {
    if (this != &src) {
        _N = src._N;
        _numbers = src._numbers;
    }
    return *this;
}

void Span::addNumber(int num) {
    if (_numbers.size() >= _N) {
        throw AddNumberException();
    }
    _numbers.push_back(num);
}

unsigned int Span::shortestSpan() {
    if (_numbers.size() < 2) {
        throw AddNumberException();
    }
    std::sort(_numbers.begin(), _numbers.end());
    unsigned int minSpan = UINT_MAX;
    for (size_t i = 1; i < _numbers.size(); i++) {
        unsigned int span = _numbers[i] - _numbers[i-1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

unsigned int Span::longestSpan() {
    if (_numbers.size() < 2) {
        throw AddNumberException();
    } //max_elem STL algo
    return *std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end());
}

const char *Span::AddNumberException::what() const throw() {
    return "(Can't add number)";
}

const char *Span::InvalArgException::what() const throw() {
    return "(Invalid iterator range)";
}

const char *Span::OutOfRangeException::what() const throw() {
    return "(Range filling would go out of range of the Span instance)";
}