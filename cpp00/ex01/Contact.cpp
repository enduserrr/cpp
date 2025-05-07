# include "Contact.hpp"

/**
 * @brief	As member funcs of the class, they're allowed to
 *			modify private member variables.
 */

std::string	Contact::get_name() {
	return (this->_name);
}

std::string	Contact::get_surname() {
	return (this->_surname);
}

std::string	Contact::get_nickname() {
	return (this->_nickname);
}

std::string	Contact::get_mobile() {
	return (this->_mobile);
}

void	Contact::set_name(std::string firstname) {
	this->_name = firstname;
}

void	Contact::set_surname(std::string lastname) {
	this->_surname = lastname;
}

void	Contact::set_nickname(std::string nickename) {
	this->_nickname = nickename;
}

void	Contact::set_mobile(std::string phonenumber) {
	this->_mobile = phonenumber;
}
