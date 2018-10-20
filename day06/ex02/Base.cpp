/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 23:06:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/10 23:06:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"




Base::Base()
{}

Base::~Base()
{}

Base::Base(const Base &other)
{
	(void)other;
}

Base& Base::operator=(const Base &other)
{
	(void)other;
	return *this;
}
