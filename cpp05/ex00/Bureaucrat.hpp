/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:25:57 by asalo             #+#    #+#             */
/*   Updated: 2025/03/26 10:53:03 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept> // For exception classes

class Bureaucrat {

private:
    const std::string   name;
    int                 grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &src);
    ~Bureaucrat();

    Bureaucrat  &operator=(const Bureaucrat &src);

    const std::string& getName() const;
    int     getGrade() const;
    void    incrementGrade();
    void    decrementGrade();

    class GradeTooHighException : public std::exception {
        public:
            const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
            const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
