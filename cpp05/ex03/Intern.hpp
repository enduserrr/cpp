/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:13:31 by asalo             #+#    #+#             */
/*   Updated: 2025/03/26 11:16:26 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {

public:
    Intern();
    Intern(const Intern &src);
    ~Intern();

    Intern &operator=(const Intern &src);

    AForm *makeForm(const std::string& formName, const std::string& target);
};

#endif
