/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 19:46:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/09/17 19:46:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

void		ZombieEvent::setZombieType()
{
	std::cout << "Enter type of your zombie" << std::endl;
	std::cin.clear();
	std::getline (std::cin, type_of_zombie_);
}

Zombie*		ZombieEvent::newZombie(std::string name)
{
	Zombie	*zombie;

	setZombieType();
	zombie = new Zombie(name, type_of_zombie_);
	return (zombie);
}

std::string ZombieEvent::get_type_of_zombie(void)
{
	return (type_of_zombie_);
}

void	randomChump(void)
{
	Zombie		random_zombie;
	ZombieEvent	random_zombie_event;
	std::string	random_names[8] = {"Rob", "Bob", "Clara", "Liza", "Jack", "Piter", "Luk", "Mika"};
	std::string	random_types[5] = {"north", "south", "east", "west", "central"};
	int			idx;

	idx = rand() % 8;
	random_zombie.set_name(random_names[idx]);
	idx = rand() % 5;
	random_zombie.set_type(random_types[idx]);
	random_zombie.announce();
}
