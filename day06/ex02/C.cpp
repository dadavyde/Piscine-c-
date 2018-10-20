/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 23:09:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/10 23:09:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "C.hpp"
#include "Base.hpp"

C::C()
{
	std::cout << "C was create" << std::endl;
}

C::~C()
{}

C::C(const C &other)
{
	(void)other;
}

C& C::operator=(const C &other)
{
	(void)other;
	return *this;
}