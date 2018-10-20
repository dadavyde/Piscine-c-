/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 19:52:53 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/03 19:52:55 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name_(name), weapon_(weapon)
{}

HumanA::~HumanA()
{}

void    HumanA::attack()
{
    std::cout << name_ << " attacks with his " << weapon_.getType() << std::endl;
}
