/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 20:39:46 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/03 20:39:48 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

int main()
{
	Zombie		*my_zombie;
	ZombieEvent	my_zombie_event;
	std::string	name;

	srand(time(0));
	std::cout << "\tSome random zombies:" << std::endl;
	randomChump();
	randomChump();
	std::cout << "\n\tCreate you own zombie\nEnter name of your zombie" << std::endl;
	std::cin.clear();
	std::getline (std::cin, name);
	if (std::cin.eof()==1)
		exit(0);
	my_zombie = my_zombie_event.newZombie(name);
	my_zombie->announce();
	delete(my_zombie);
}
