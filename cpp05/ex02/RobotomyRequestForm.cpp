/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:02:19 by asalo             #+#    #+#             */
/*   Updated: 2025/04/07 11:59:13 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45, target) {
    srand(time(0)); //Seed the random number generator
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): AForm(src) {
    srand(time(0)); //Seed the random number generator
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
    if (this != &src) {
		AForm::operator=(src);
	}
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (!getIsSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw GradeTooLowException();
    }
    action();
}

void RobotomyRequestForm::action() const {
    std::cout << "Drrrrrrrrrrrrrrrrr... Drrrrrrrrrrrr... DRRRRrrRR.." << std::endl;
    if (rand() % 2 == 0) {
        std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed on " << getTarget() << "." << std::endl;
    }
}
