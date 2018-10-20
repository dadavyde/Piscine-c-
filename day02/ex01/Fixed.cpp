/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 11:44:20 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/04 11:44:21 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::num_fractional_bits = 8;

Fixed::Fixed() : fixed_point_value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int a) {
    std::cout << "Int constructor called" << std::endl;
    fixed_point_value = a << num_fractional_bits;
}

Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    int    sign = 1;
    float  new_f = f;

    if (f < 0)
    {
        new_f = -f;
        sign = -1;
    }
    fixed_point_value = sign * (int)(new_f * pow(2, num_fractional_bits) + 0.5f);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other) {
    std::cout << "Assignation operator called" << std::endl;
    if (this != &other)
    {
        fixed_point_value = other.getRawBits();
    }
    return *this;
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}


int Fixed::getRawBits(void) const
{
    return fixed_point_value;
}

void Fixed::setRawBits(int const raw) {
    fixed_point_value = raw;
}

int Fixed::toInt() const {
    int    sign = 1;
    int    new_value = fixed_point_value;

    if (fixed_point_value < 0)
    {
        new_value = -new_value;
        sign = -1;
    }
    return (sign * (new_value >> num_fractional_bits));
}

float Fixed::toFloat() const {
    
    return (fixed_point_value / pow(2, num_fractional_bits));
}
