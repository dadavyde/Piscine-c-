/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 23:09:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/10 23:09:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "Base.hpp"

A::A()
{
	std::cout << "A was create" << std::endl;
}

A::~A()
{}

A::A(const A &other)
{
	(void)other;
}

A& A::operator=(const A &other)
{
	(void)other;
	return *this;
}