/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 14:28:01 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/04 14:28:02 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::num_fractional_bits = 8;

Fixed::Fixed() : fixed_point_value(0)
{}

Fixed::Fixed(const int a) {
    
    fixed_point_value = a << num_fractional_bits;
}

Fixed::Fixed(const float f) {
    int    sign = 1;
    float  new_f = f;

    if (f < 0)
    {
        new_f = -f;
        sign = -1;
    }
    fixed_point_value = sign * (int)(new_f * pow(2, num_fractional_bits) + 0.5f);
}

Fixed::~Fixed() 
{}

Fixed::Fixed(const Fixed &other) {
    if (this != &other)
    {
        fixed_point_value = other.getRawBits();
    }
}

Fixed& Fixed::operator =(const Fixed &other) {
    if (this != &other)
    {
        fixed_point_value = other.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits(void) const
{
    return fixed_point_value;
}

void Fixed::setRawBits(int const raw) {
    fixed_point_value = raw;
}

int Fixed::get_num_fract_bits(void) const
{
    return num_fractional_bits;
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


std::ostream& operator <<(std::ostream& cout, const Fixed& a)  
{
    cout << a.toFloat();
    return cout;
}

//Перезагрузка сравнительный операторов

bool Fixed::operator < (const Fixed &a)
{
    return (fixed_point_value < a.getRawBits());
}

bool Fixed::operator < (const Fixed &a) const
{
    return (fixed_point_value < a.getRawBits());
}

bool Fixed::operator > (const Fixed &a)
{
    return (fixed_point_value > a.getRawBits());
}

bool Fixed::operator > (const Fixed &a) const
{
    return (fixed_point_value > a.getRawBits());
}

bool Fixed::operator <= (const Fixed &a)
{
    return (fixed_point_value <= a.getRawBits());
}

bool Fixed::operator <= (const Fixed &a) const
{
    return (fixed_point_value <= a.getRawBits());
}

bool Fixed::operator >= (const Fixed &a)
{
    return (fixed_point_value >= a.getRawBits());
}

bool Fixed::operator >= (const Fixed &a) const
{
    return (fixed_point_value >= a.getRawBits());
}

bool Fixed::operator == (const Fixed &a)
{
    return (fixed_point_value == a.getRawBits());
}

bool Fixed::operator == (const Fixed &a) const
{
    return (fixed_point_value == a.getRawBits());
}

bool Fixed::operator != (const Fixed &a)
{
    return !(*this == a);
}

bool Fixed::operator != (const Fixed &a) const
{
    return !(*this == a);
}

//Перезагрузка арифметических операторов

Fixed Fixed::operator + (const Fixed &a)
{
    Fixed  sum;

    sum.setRawBits(fixed_point_value + a.getRawBits());
    return (sum);
}

Fixed Fixed::operator + (const Fixed &a) const
{
    Fixed  sum;

    sum.setRawBits(fixed_point_value + a.getRawBits());
    return (sum);
}

Fixed Fixed::operator - (const Fixed &a)
{
    Fixed  sum;

    sum.setRawBits(fixed_point_value - a.getRawBits());
    return (sum);
}

Fixed Fixed::operator - (const Fixed &a) const
{
    Fixed  sum;

    sum.setRawBits(fixed_point_value - a.getRawBits());
    return (sum);
}

Fixed Fixed::operator * (const Fixed &a)
{
    long   mult_bits;
    Fixed  mult;

    mult_bits = fixed_point_value * a.getRawBits();
    mult.setRawBits((int)(mult_bits >> num_fractional_bits));
    return (mult);
}

Fixed Fixed::operator * (const Fixed &a) const
{
    long   mult_bits;
    Fixed  mult;

    mult_bits = fixed_point_value * a.getRawBits();
    mult.setRawBits((int)(mult_bits >> num_fractional_bits));
    return (mult);
}

Fixed Fixed::operator / (const Fixed &a)
{
    float   div_bits;

    div_bits = fixed_point_value / a.getRawBits();
    return (Fixed(div_bits));
}

Fixed Fixed::operator / (const Fixed &a) const
{
    float   div_bits;

    div_bits = fixed_point_value / a.getRawBits();
    return (Fixed(div_bits));
}

//Перезагрузка ++ --

Fixed Fixed::operator ++ (int)
{
    Fixed  incr(*this);

    fixed_point_value++;
    return (incr);
}

Fixed Fixed::operator ++ ()
{
    ++fixed_point_value;
    return (*this);
}

Fixed Fixed::operator -- (int)
{
    Fixed  decr(*this);

    fixed_point_value--;
    return (decr);
}

Fixed Fixed::operator -- ()
{
    --fixed_point_value;
    return (*this);
}

//min max

Fixed&  Fixed::min(Fixed &a, Fixed &b)
{
    if (a <= b)
        return a;
    else
        return b;
}


const Fixed&  Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a <= b)
        return a;
    else
        return b;
}

Fixed&  Fixed::max(Fixed &a, Fixed &b)
{
    if (a >= b)
        return a;
    else
        return b;
}


const Fixed&  Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a >= b)
        return a;
    else
        return b;
}
