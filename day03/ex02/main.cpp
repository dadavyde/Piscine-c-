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
#include "ScavTrap.hpp"

int main()
{
	std::string		name;
	std::string		command;
	int	enemy_attack;
	int  no_come = 0;

	srand(time(0));
	std::cout << "Welcome to Borderlands: demo read-write version. "
				 "Hope, you'll enjoy our game.\n \t\tLets daaaaaanccccce" << std::endl;
	std::cout << "Your Claptraps allmoust ready...\nPlease, name your FragTrap robot:  ";
	std::cin.clear();
	std::getline (std::cin, name);
	if (std::cin.eof()==1)
		exit(0);

	FragTrap  frag_trap(name);

	std::cout << "Please, name your ScavTrap robot:  ";
	std::cin.clear();
	std::getline (std::cin, name);
	if (std::cin.eof()==1)
		exit(0);

	ScavTrap  scav_trap(name);

	std::cout << "With "<< frag_trap.get_name() << " you can attack with:\n"
												"\t1 - for ranged attack\n"
												"\t2 - for melee attack\n"
												"\t3 - for VaultHunter.EXE." << std::endl;
	std::cout << "\nWith "<< scav_trap.get_name() << " you can attack with:\n"
												"\t4 - for ranged attack\n"
												"\t5 - for melee attack\n"
												"\t6 - for challengeNewcomer" << std::endl;
	while (1)
	{
		std::getline (std::cin, command);
		if (std::cin.eof()==1)
			exit(0);
		else if (command.size() == 1 && command[0] >= '1' && command[0] <= '6')
		{
			if (command[0] == '1')
				frag_trap.rangedAttack("enemy");
			else if (command[0] == '2')
				frag_trap.meleeAttack("enemy");
			else if (command[0] == '3')
				frag_trap.vaulthunter_dot_exe("enemy");
			else if (command[0] == '4')
				scav_trap.rangedAttack("enemy");
			else if (command[0] == '5')
				scav_trap.meleeAttack("enemy");
			else
			{
				if (scav_trap.challengeNewcomer("enemy"))
					no_come = 1;
			}
		}
		if (frag_trap.get_hp() == 0 || scav_trap.get_hp() == 0)
			return (0);
		enemy_attack = (unsigned)abs(rand() % 5);
		if (enemy_attack == 2 || enemy_attack == 3)
		{
			if (no_come == 1)
			{
				std::cout << "ScavTrap " << scav_trap.get_name() << " blocked the enemies" << std::endl;
				no_come = 0;
			}
			else if (!frag_trap.takeDamage(enemy_attack * 10) || !scav_trap.takeDamage(enemy_attack * 10))
				break ;
		}
		else if (enemy_attack == 4)
		{
			frag_trap.beRepaired(15);
			scav_trap.beRepaired(10);
		}
	}
	return 0;
}
