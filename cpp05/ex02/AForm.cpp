#include "AForm.hpp"

AForm::AForm(): _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150), _target("default") {}

AForm::AForm(const std::string &name, int _gradeToSign, int _gradeToExecute, const std::string &target)
    : _name(name), _isSigned(false), _gradeToSign(_gradeToSign), _gradeToExecute(_gradeToExecute), _target(target) {
    if (_gradeToSign < 1 || _gradeToExecute < 1) {
        throw GradeTooHighException();
    }
    if (_gradeToSign > 150 || _gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

AForm::AForm(const AForm &src): _name(src.getName()), _isSigned(src.getIsSigned()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute()), _target(src.getTarget()) {}

AForm &AForm::operator=(const AForm &src) {
    if (this != &src) {
        _isSigned = src._isSigned;
    }
    return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const {
    return _isSigned;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

const std::string &AForm::getTarget() const {
    return _target;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw GradeTooLowException();
    }
    _isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "grade too low";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "form not signed";
}

std::ostream& operator<<(std::ostream &outStream, const AForm& form) {
    outStream << "Form: " << form.getName() << ", signed: "
                << (form.getIsSigned() ? "YES" : "NO")
                << ", grade to sign: " << form.getGradeToSign()
                << ", grade to execute: " << form.getGradeToExecute() << ", target: "
                << form.getTarget() << ".";
    return outStream;
}
