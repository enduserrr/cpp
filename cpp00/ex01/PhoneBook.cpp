/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:21:35 by asalo             #+#    #+#             */
/*   Updated: 2024/08/13 11:21:38 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"


Phonebook::Phonebook(){_current = 0;_index = 0;};

void    print_phonebook() {
    std::cout << "/* ************************************** */" << std::endl;
    std::cout << "/*                PHONEBOOK:              */" << std::endl;
    std::cout << "/*                1-ADD                   */" << std::endl;
    std::cout << "/*                2-SEARCH                */" << std::endl;
    std::cout << "/*                3-EXIT                  */" << std::endl;
    std::cout << "/* ************************************** */" << std::endl;
}

void	Phonebook::add_contact() {
	Contact tmp;

	std::cout << "First Name: ";
	getline(std::cin, _firstname);
	tmp.set_name(_firstname);
	std::cout << "Last Name: ";
	getline(std::cin, _lastname);
	tmp.set_surname(_lastname);
	std::cout << "Nickename: ";
	getline(std::cin, _nickename);
	tmp.set_nickname(_nickename);
	std::cout << "Mobile number: ";
	getline(std::cin, _phonenumber);
	tmp.set_mobile(_phonenumber);
	this->_contacts[_current % 8] = tmp;
	this->_current++;
	if (this->_current <= 8)
		this->_index = this->_current;
	std::cout << "NEW CONTACT ADDED" << std::endl;
}

std::string	resize(std::string content) {
	if (content.length() > 10) {
		content.erase(content.begin() + 9, content.end());
		content.append(".");
	}
	return (content);
}

void	Phonebook::print_phonebook_contacts() {
	std::cout << WHITE
	<< "|     #    |   NAME   |  SURNAME | NICKNAME |\n"
	<< RES;
	for (int i = 0; i < (int)this->_index; i++) {
		std::cout
		<< "|" << std::setw(10) << i
		<< "|" << std::setw(10) << resize(_contacts[i].get_name())
		<< "|" << std::setw(10) << resize(_contacts[i].get_surname())
		<< "|" << std::setw(10) << resize(_contacts[i].get_nickname()) << "|"
		<< std::endl;
	}
}

void	Phonebook::search_contact() {
	unsigned int index;

	print_phonebook_contacts();
	std::cout << "Enter index number: ";
	std::cin >> index;
	if (std::cin.fail())
		std::cout << "Invalid index number\n";
	else {
		if (index < this->_index) {
			std::cout << "First Name: " << this->_contacts[index].get_name() << std::endl;
			std::cout << "Last Name: " << this->_contacts[index].get_surname() << std::endl;
			std::cout << "NickeName: " << this->_contacts[index].get_nickname() << std::endl;
			std::cout << "Phone Number: " << this->_contacts[index].get_mobile() << std::endl;
		} else
			std::cout << "Invalid index number\n";
	}
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}

int main() {
    Phonebook Phonebook;
    std::string command;

    print_phonebook();
    for (;;) {
		if (std::cin.eof() == true) {
			std::cout << "^D" << std::endl;
			exit(0);
		}
        std::cout << "> ";
        getline(std::cin, command);
        if (command == "ADD")
            Phonebook.add_contact();
        else if (command == "SEARCH")
			Phonebook.search_contact();
        else if (command == "EXIT") {
			std::cout << "See ya" << std::endl;
			break ;
		} else
            std::cout << "Command not found" << std::endl;
    }
	return (0);
}
