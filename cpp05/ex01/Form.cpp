/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:27:52 by asalo             #+#    #+#             */
/*   Updated: 2025/04/06 17:54:54 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Form.hpp"

Form::Form() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string& name, int _gradeToSign, int _gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(_gradeToSign), _gradeToExecute(_gradeToExecute) {
    if (_gradeToSign < 1 || _gradeToExecute < 1) {
        throw GradeTooHighException();
    }
    if (_gradeToSign > 150 || _gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

Form::Form(const Form &src) : _name(src.getName()), _isSigned(src.getIsSigned()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute()) {}

Form &Form::operator=(const Form &src) {
    if (this != &src) {
        this->_isSigned = src.getIsSigned();
	}
    return *this;
}

Form::~Form() {}

const std::string& Form::getName() const {
    return _name;
}

bool Form::getIsSigned() const {
    return _isSigned;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw GradeTooLowException();
    }
    _isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "(grade too high)";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "(grade too low)";
}

std::ostream &operator<<(std::ostream& outStream, const Form& form) {
    outStream   << "Form: " << form.getName() << ", signed: "
                << (form.getIsSigned() ? "y" : "n") << ", grade to sign: "
                << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute() << ".";
    return outStream;
}
