/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:57:32 by asalo             #+#    #+#             */
/*   Updated: 2024/10/11 16:57:35 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << WB << a << std::endl;
    std::cout << WB << ++a << std::endl;
    std::cout << WB << a << std::endl;
    std::cout << WB << a++ << std::endl;
    std::cout << WB << a << std::endl;
    std::cout << WB << b << std::endl;
    std::cout << WB << Fixed::max( a, b ) << std::endl;
    return 0;
}
