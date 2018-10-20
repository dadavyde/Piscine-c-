/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:05:25 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/13 17:05:26 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


Span::Span(unsigned int N) : size_(N) {}

Span::~Span()
{}

Span &Span::operator=(const Span &other){
    this->size_ = other.size_;
    this->numbers = other.numbers;
    return *this;
}

Span::Span(const Span &other) {
    *this = other;
}

void Span::addNumber(unsigned int n)
{
    if (numbers.size() == size_)
        throw std::out_of_range("Can't add new number, container is full!");
    else
        numbers.push_back(n);
}

size_t Span::shortestSpan()
{
    if(numbers.size() < 2)
        throw std::exception();
    std::vector<int> sor_v = numbers;
    std::sort(sor_v.begin(), sor_v.end());

    size_t  diff = static_cast<size_t >(sor_v[1] - sor_v[0]);
    for (std::vector<int>::iterator it = sor_v.begin() + 1 ; it != sor_v.end(); ++it)
    {
        if (static_cast<size_t >(*it - *(it - 1)) < diff)
            diff = static_cast<size_t >(*it - *(it - 1));
    }
    return diff;
}

size_t Span::longestSpan() {
    if (numbers.size() < 2)
        throw std::exception();
    return  static_cast<size_t >(*std::max_element(numbers.begin(), numbers.end()) -
                                 *std::min_element(numbers.begin(), numbers.end()));
}
