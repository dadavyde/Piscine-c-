/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:05:32 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/13 17:05:33 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>


class Span {
public:
    Span(unsigned int N);
    virtual ~Span();
    Span &operator=(const Span &other);
    Span(const Span &other);
    void addNumber(unsigned int n);

    template <typename Iter>
    void addRangeNumbers(Iter start, Iter end)
    {
        for(Iter it = start; it < end; it++)
        {
            addNumber(*it);
        }
    }
    size_t  shortestSpan();
    size_t  longestSpan();

private:
    unsigned int  size_;
    std::vector<int> numbers;
};


#endif
