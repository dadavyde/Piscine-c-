/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 23:09:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/10 23:09:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "B.hpp"
#include "Base.hpp"

B::B()
{
	std::cout << "B was create" << std::endl;
}

B::~B()
{}

B::B(const B &other)
{
	(void)other;
}

B& B::operator=(const B &other)
{
	(void)other;
	return *this;
}