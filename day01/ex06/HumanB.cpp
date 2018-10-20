/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 19:54:43 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/03 19:54:44 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name_(name), weapon_(NULL)
{}

HumanB::~HumanB()
{}

void    HumanB::attack()
{
    std::cout << name_ << " attacks with his " << weapon_->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	weapon_ = &weapon;
}
