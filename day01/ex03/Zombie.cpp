/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 19:45:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/09/17 19:45:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void)
{
	if (name_ == "Garry")
		std::cout << '<' << name_ << " (" << type_ << ")> It's close to midnight and something evil's lurking in the darrrk" << std::endl;
	else if (name_ == "Mary")
		std::cout << '<' << name_ << " (" << type_ << ")> Under the moonlight you see a sight that almost stops your hearrrt" << std::endl;
	else if (name_ == "David")
		std::cout << '<' << name_ << " (" << type_ << ")> You try to scream but terror takes the sound before you make ittt" << std::endl;
	else if (name_ == "Chloe")
		std::cout << '<' << name_ << " (" << type_ << ")> You start to freeze as horror looks you right between the eyesss" << std::endl;
	else if (name_ == "Michael")
		std::cout << '<' << name_ << " (" << type_ << ")> You're paralyzeddd" << std::endl;
	else
		std::cout << '<' << name_ << " (" << type_ << ")> Cause this is thrilleeeeer, thriiiiller night!" << std::endl;
}

void Zombie::set_name(std::string name)
{
	name_ = name;
}

void Zombie::set_type(std::string type)
{
	type_ = type;
}

Zombie::Zombie()
{}

Zombie::Zombie(std::string name, std::string type) : name_(name), type_(type)
{}

Zombie::~Zombie()
{}


