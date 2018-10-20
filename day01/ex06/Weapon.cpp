/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 20:03:54 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/03 20:03:55 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type_(type)
{}

Weapon::~Weapon()
{}

std::string& Weapon::getType()
{
    return (type_);
}

void Weapon::setType(std::string type)
{
    type_ = type;
}
