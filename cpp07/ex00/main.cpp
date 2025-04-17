/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:15:12 by asalo             #+#    #+#             */
/*   Updated: 2025/04/17 11:44:31 by asalo            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>
#include <string>
#include "Whatever.hpp"

#define REV_BLD_GREY    "\033[1;90;107m"
#define RES             "\033[0m"

int main( void ) {
    int a = 7;
    int b = 3;
    std::cout << REV_BLD_GREY << "## INT ##" << RES << std::endl;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    ::swap( a, b );
    std::cout << "After swap:  a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::cout << std::endl;

    std::string c = "string1";
    std::string d = "string2";
    std::cout << REV_BLD_GREY << "## STRING ##" << RES << std::endl;
    std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "After swap:  c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    std::cout << std::endl;

    const int aConst = 10;
    const int bConst = 20;
    std::cout << REV_BLD_GREY "## CONST ##" RES << std::endl;
    std::cout << "max(aConst, bConst) = " << ::max(aConst, bConst) << std::endl;
    std::cout << std::endl;

    int e = 5;
    int f = 5;
    std::cout << REV_BLD_GREY "## EQUALS ##" RES << std::endl;
    std::cout << "e = " << e << ", f = " << f << std::endl;
    std::cout << "min(e, f) returns second? " << ( &::min(e, f) == &f ? "Yes" : "No" ) << std::endl;
    std::cout << "max(e, f) returns second? " << ( &::max(e, f) == &f ? "Yes" : "No" ) << std::endl;
    
    return 0;
}