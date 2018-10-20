/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 17:20:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/09/22 17:20:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N)
{
	std::string		random_names[6] = {"Garry", "Mary", "David", "Chloe", "Michael", "Jordan"};
	std::string		random_types[4] = {"north", "south", "east", "west"};
	int								  idx;

	num_of_zombies_ = N;
	zombies_arr = new Zombie[N];
	for (int i = 0; i < num_of_zombies_; i++)
	{
		idx = rand() % 6;
		zombies_arr[i].set_name(random_names[idx]);
		idx = rand() % 4;
		zombies_arr[i].set_type(random_types[idx]);
	}
}

ZombieHorde::~ZombieHorde()
{
	delete [] zombies_arr;
	std::cout << "\nYour zombies were successfully destroyed!" << std::endl;
}

void ZombieHorde::announce()
{
	for(int i = 0; i < num_of_zombies_; i++)
		zombies_arr[i].announce();
}
