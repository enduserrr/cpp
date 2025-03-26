/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:13:43 by asalo             #+#    #+#             */
/*   Updated: 2025/03/26 11:13:45 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;
    const std::string target;

public:
    AForm(); //added
    AForm(const std::string& name, int gradeToSign, int gradeToExecute, const std::string& target);
    AForm(const AForm &src);
    virtual ~AForm();

    AForm &operator=(const AForm &src);

    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    const std::string& getTarget() const;

    void beSigned(const Bureaucrat& bureaucrat);
    virtual void execute(Bureaucrat const & executor) const = 0; // Abstract function

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
