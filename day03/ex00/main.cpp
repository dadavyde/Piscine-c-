/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:16:42 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/05 17:16:43 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	std::string		name;
	std::string		command;
	int	enemy_attack;

	srand(time(0));
	std::cout << "Welcome to Borderlands: demo read-write version. "
			  "Hope, you'll enjoy our game.\n \t\tLets daaaaaanccccce" << std::endl;
	std::cout << "Your Claptrap allmoust ready...\nPlease, name your robot:  ";
	std::cin.clear();
	std::getline (std::cin, name);
	if (std::cin.eof()==1)
		exit(0);

	FragTrap  robot(name);

	std::cout << "Press 1 for ranged attack, 2 for melee attack and 3 for VaultHunter.EXE." << std::endl;
	while (1)
	{
		std::getline (std::cin, command);
		if (std::cin.eof()==1)
			exit(0);
		else if (command.size() == 1 && command[0] >= '1' && command[0] <= '3')
		{
			if (command[0] == '1')
				robot.rangedAttack("enemy");
			else if (command[0] == '2')
				robot.meleeAttack("enemy");
			else
				robot.vaulthunter_dot_exe("enemy");
		}
		else
			std::cout << "Please, enter the valid command!" << std::endl;
		if (robot.get_hp() == 0)
			return (0);
		enemy_attack = (unsigned)abs(rand() % 5);
		if (enemy_attack == 2 || enemy_attack == 3)
		{
			if (robot.takeDamage(enemy_attack * 10) == 0)
				break ;
		}
		else if (enemy_attack == 4)
			robot.beRepaired(15);
	}
	return 0;
}
