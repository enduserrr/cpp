#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>

class Span {
    private:
        unsigned int _N;
        std::vector<int> _numbers;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span& src);
        Span& operator=(const Span& src);
        ~Span();

        unsigned int shortestSpan();
        unsigned int longestSpan();

        void addNumber(int num);
        
        /**
         * @brief   std::distance:      Counts the nb of elements between iterator begin and end.
         *          difference_type:    The data type 'std::distance' returns, defined by the iterator itself (iterator_traits)
         *
         *          => Ensures safe handling of errors (signed negative int types)
         */
        template <typename InputIterator>
        void multiAdd(InputIterator begin, InputIterator end) {
            // 'iterator_traits' to get the 'difference_type'
            typename std::iterator_traits<InputIterator>::difference_type count = std::distance(begin, end);
            if (count < 0) {
                throw InvalArgException();
            }
            if (this->_numbers.size() + static_cast<unsigned int>(count) > this->_N) {
                throw OutOfRangeException();
            }
            this->_numbers.insert(this->_numbers.end(), begin, end);
        };

        class AddNumberException : public std::exception {
            public:
                const char* what() const throw();
        };
        class InvalArgException : public std::exception {
            public:
                const char* what() const throw();
        };
        class OutOfRangeException : public std::exception {
            public:
                const char* what() const throw();
        };
};

#endif