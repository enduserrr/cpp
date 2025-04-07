#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

#define GC      "\033[3;90m"
#define RES     "\033[0m"

class Bureaucrat;

class AForm {

private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
    const std::string _target;

public:
    AForm();
    AForm(const std::string &name, int gradeToSign, int gradeToExecute, const std::string &target);
    AForm(const AForm &src);
    virtual ~AForm();

    AForm &operator=(const AForm &src);

    const std::string &getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    const std::string &getTarget() const;

    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const & executor) const = 0; // Pure virtual, abstract func

    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream& outStream, const AForm &form);

#endif
