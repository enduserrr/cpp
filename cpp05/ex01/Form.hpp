/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:27:57 by asalo             #+#    #+#             */
/*   Updated: 2025/03/26 10:28:11 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"  // Include for interaction with Bureaucrat

class Bureaucrat; // Forward declaration

class Form {

private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

public:
    Form(); //default constructor
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form &src);
    ~Form();

    Form &operator=(const Form &src);

    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
