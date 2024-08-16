/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:21:47 by asalo             #+#    #+#             */
/*   Updated: 2024/08/13 11:21:49 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <climits>
# include <iomanip>

# define WHITE    "\033[1;97m"
# define RES      "\033[0m"

class Phonebook
{
    private:
        Contact         _contacts[8];
        unsigned int    _current;
        unsigned int    _index;
        std::string     _firstname;
        std::string     _lastname;
        std::string     _nickename;
		std::string     _darkestsecret;
		std::string     _phonenumber;
    public:
        Phonebook();
        ~Phonebook(){};
        void            add_contact();
        void            search_contact();
		void            print_phonebook_contacts();
};

#endif
