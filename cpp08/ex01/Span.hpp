/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 08:18:32 by asalo             #+#    #+#             */
/*   Updated: 2025/04/22 08:39:15 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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

        void addNumber(int num);
        void addRange(int* begin, int* end);

        unsigned int shortestSpan();
        unsigned int longestSpan();

        class AddNumberException : public std::exception {
            public:
                const char* what() const throw();
        };
};

#endif