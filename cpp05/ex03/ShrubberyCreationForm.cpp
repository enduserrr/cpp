#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
    if (this != &src) {
        AForm::operator=(src);
	}
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (!getIsSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw GradeTooLowException();
    }
    action();
}

void ShrubberyCreationForm::action() const {
    std::ofstream outputFile(getTarget() + "_shrubbery");
    if (outputFile.is_open()) {
        outputFile << "       _-_" << std::endl;
        outputFile << "    /\\     /\\" << std::endl;
        outputFile << "   /  \\   /  \\" << std::endl;
        outputFile << "  /    \\ /    \\" << std::endl;
        outputFile << " /______\\/______\\" << std::endl;
        outputFile << "        I" << std::endl;
        outputFile << "        I" << std::endl;
        outputFile << "        I" << std::endl;
        outputFile.close();
    } else {
        std::cerr << "Error: Could not open file for shrubbery creation." << std::endl;
    }
}
