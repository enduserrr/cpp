/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:22:15 by asalo             #+#    #+#             */
/*   Updated: 2024/08/13 11:22:17 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
    private:
        std::string		_name;
        std::string		_surname;
        std::string		_nickname;
        std::string		_mobile;
    public:
        Contact(){};
        ~Contact(){};
        std::string		get_name();
        std::string		get_surname();
        std::string		get_nickname();
        std::string		get_mobile();

        void            set_name(std::string firstname);
        void            set_surname(std::string lastname);
        void            set_nickname(std::string nickename);
        void            set_mobile(std::string phonenumber);
};

#endif
