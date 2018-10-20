/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 19:31:21 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/03 19:31:24 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

int main()
{
	ZombieHorde		*our_zombies;
	int				num;

	srand(time(0));
	std::cout << "How much zombies do you want to create?" << std::endl;
	std::cin.clear();
	std::cin >> num;
	while (num < 1)
	{
		std::cout << "Enter good number of zombies, please" << std::endl;
		std::cin.clear();
		std::cin >> num;
	}
	our_zombies = new ZombieHorde(num);
	std::cout << "Your zombies were successfully created!\n" << std::endl;
	our_zombies->announce();
	delete(our_zombies);
}
