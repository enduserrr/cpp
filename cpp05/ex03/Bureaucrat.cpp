/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:27:03 by asalo             #+#    #+#             */
/*   Updated: 2025/04/07 11:55:53 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) {
    if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src.getName()), _grade(src.getGrade()) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
    if (this != &src) {
		this->_grade = src.getGrade();
	}
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() {
    if (_grade <= 1) {
        throw GradeTooHighException();
    }
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150) {
        throw GradeTooLowException();
    }
    _grade++;
}

void Bureaucrat::signForm(AForm &form) {
    try {
        form.beSigned(*this);
        std::cout << WB << _name << RES << " signed the form: " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << WB << _name << RES << " couldn't sign the form: " << form.getName() << " (" << e.what() << ")" << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) {
    try {
        form.execute(*this);
        std::cout << WB << _name << RES << " executed the form: " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << WB << _name << RES << " couldn't execute the form: " << form.getName() << " (" << e.what() << ")" << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "(grade too high)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "(grade too low)";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << WB << bureaucrat.getName() << RES << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}
