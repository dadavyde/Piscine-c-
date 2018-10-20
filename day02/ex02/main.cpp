/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 11:44:12 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/04 11:44:13 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>


int main( void ) {
    Fixed   a;
    Fixed   const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed   c(1.25f);
    Fixed   d(2.75f);

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout <<"c + d = "<< c + d << std::endl;
    std::cout <<"c - d = "<< c - d << std::endl;
    std::cout <<"c * d = "<< c * d << std::endl;
    std::cout <<"c / d = "<< c / d << std::endl;
    
    std::cout << Fixed::max( a, b ) << std::endl;

    return 0;
}

