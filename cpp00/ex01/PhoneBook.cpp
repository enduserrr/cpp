# include "PhoneBook.hpp"

/**
 * @brief	Global functions (non-static) are defined outside of any class.
 *			Can be called from anywhere in the program without needing an
 *			instance of any class. No access to any private or protected
 *			members of any class unless an instance is explicitly passed into
 *			one as a parameter.
 */

/* Constructor for the phonebook class */
Phonebook::Phonebook(){_current = 0;_index = 0;};

/* Global function */
void    print_phonebook() {
    std::cout << "/* ************************************** */" << std::endl;
    std::cout << "/*                PHONEBOOK:              */" << std::endl;
    std::cout << "/*                1-ADD                   */" << std::endl;
    std::cout << "/*                2-SEARCH                */" << std::endl;
    std::cout << "/*                3-EXIT                  */" << std::endl;
    std::cout << "/* ************************************** */" << std::endl;
}

/* Member function */
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

/* Global function */
std::string	resize(std::string content) {
	if (content.length() > 10) {
		content.erase(content.begin() + 9, content.end());
		content.append(".");
	}
	return (content);
}

/* Member function */
void	Phonebook::print_phonebook_contacts() {
	std::cout << WHITE
	<< "|     #    |   NAME   |  SURNAME | NICKNAME |\n"
	<< RES;
	for (int i = 0; i < (int)this->_index; i++) {
		std::cout
		<< "|" << std::setw(10) << i
		<< "|" << std::setw(10) << resize(_contacts[i].get_name())
		<< "|" << std::setw(10) << resize(_contacts[i].get_surname())
		<< "|" << std::setw(10) << resize(_contacts[i].get_nickname())
		<< "|"
		<< std::endl;
	}
}

/* Member function */
void	Phonebook::search_contact() {
	unsigned int i;

	print_phonebook_contacts();
	std::cout << "Enter index number: ";
	std::cin >> i;
	if (std::cin.fail())
		std::cout << "Invalid index number\n";
	else {
		if (i < this->_index) {
			std::cout << "First Name: " << this->_contacts[i].get_name() << std::endl;
			std::cout << "Surname: " << this->_contacts[i].get_surname() << std::endl;
			std::cout << "Nickname: " << this->_contacts[i].get_nickname() << std::endl;
			std::cout << "Mobile #: " << this->_contacts[i].get_mobile() << std::endl;
		} else
			std::cout << "Invalid index number\n";
	}
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}

/* Global function */
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
