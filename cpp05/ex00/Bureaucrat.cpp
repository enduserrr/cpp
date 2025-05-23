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
    }// Increment == decrease towards the highest (1)
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150) {
        throw GradeTooLowException();
    }// Decrement == increment towards the lowest (150)
    _grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &outStream, const Bureaucrat &bureaucrat) {
    outStream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return outStream;
}
