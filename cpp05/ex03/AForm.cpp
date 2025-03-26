#include "AForm.hpp"

AForm::AForm(): name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150), target("default") {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute, const std::string& target)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), target(target) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

AForm::AForm(const AForm &src): name(src.getName()), isSigned(src.getIsSigned()), gradeToSign(src.getGradeToSign()), gradeToExecute(src.getGradeToExecute()), target(src.getTarget()) {}

AForm &AForm::operator=(const AForm &src) {
    if (this != &src) {
        isSigned = src.isSigned;
    }
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const {
    return name;
}

bool AForm::getIsSigned() const {
    return isSigned;
}

int AForm::getGradeToSign() const {
    return gradeToSign;
}

int AForm::getGradeToExecute() const {
    return gradeToExecute;
}

const std::string& AForm::getTarget() const {
    return target;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign) {
        throw GradeTooLowException();
    }
    isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form: " << form.getName()
       << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << form.getGradeToSign()
       << ", Grade to Execute: " << form.getGradeToExecute()
       << ", Target: " << form.getTarget() << ".";
    return os;
}
