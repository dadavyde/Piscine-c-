/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 14:28:06 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/04 14:28:07 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>


class Fixed {
public:
    Fixed();
    Fixed(const int a);
    Fixed(const float f);
    virtual ~Fixed();
    Fixed(const Fixed &other);

    Fixed &operator=(const Fixed &other);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    int toInt( void ) const;
    float toFloat() const;
    int get_num_fract_bits(void) const;

    Fixed   operator++ (int);
    Fixed   operator++ ();
    Fixed   operator-- (int);
    Fixed   operator-- ();

    bool    operator< (const Fixed &a);
    bool    operator> (const Fixed &a);
    bool    operator<= (const Fixed &a);
    bool    operator>= (const Fixed &a);
    bool    operator== (const Fixed &a);
    bool    operator!= (const Fixed &a);
    Fixed   operator+ (const Fixed &a);
    Fixed   operator- (const Fixed &a);
    Fixed   operator* (const Fixed &a);
    Fixed   operator/ (const Fixed &a);

    bool    operator< (const Fixed &a) const;
    bool    operator> (const Fixed &a) const;
    bool    operator<= (const Fixed &a) const;
    bool    operator>= (const Fixed &a) const;
    bool    operator== (const Fixed &a) const;
    bool    operator!= (const Fixed &a) const;
    Fixed   operator+ (const Fixed &a) const;
    Fixed   operator- (const Fixed &a) const;
    Fixed   operator* (const Fixed &a) const;
    Fixed   operator/ (const Fixed &a) const;

    static Fixed&          min(Fixed &a, Fixed &b);
    static const Fixed&    min(const Fixed &a, const Fixed &b);
    static Fixed&          max(Fixed &a, Fixed &b);
    static const Fixed&    max(const Fixed &a, const Fixed &b);
    

private:
    int                 fixed_point_value;
    static const int    num_fractional_bits;
};

std::ostream& operator<<(std::ostream& os, const Fixed& a);

#endif
