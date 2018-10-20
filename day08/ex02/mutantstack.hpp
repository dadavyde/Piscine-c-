/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 16:57:35 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/13 16:57:36 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template<class T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::deque<T>::iterator iterator;

    MutantStack() {};
    virtual ~MutantStack(){};
    MutantStack(const MutantStack &other) {
        this->deque_arr = other.deque_arr;
    };
    MutantStack &operator=(const MutantStack &other)
    {
        delete this->deque_arr;
        this->deque_arr = other.deque_arr;
        return *this;
    };

    iterator begin() { return std::begin(this->c); }
    iterator end() { return std::end(this->c); }

    iterator begin() const { return std::begin(this->c); }
    iterator end() const { return std::end(this->c); }
};

#endif
