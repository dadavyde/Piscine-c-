/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 21:34:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/04 21:34:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	energy_points_ = 50;
	max_energy_points_ = 50;
	melee_attack_damage_ = 20;
	ranged_attack_damage_ = 15;
	armor_damage_reduction_ = 3;

	std::cout << "ScavTrap " << name_ << " was created!" << std::endl;
	display_hp();
	display_ep();
	std::cout << "level: " << level_
			  << "\nmelee attack damage = " << melee_attack_damage_
			  << "\nranged attack damage = " << ranged_attack_damage_
			  << "\narmor damage reduction = " << armor_damage_reduction_ << "\n" <<  std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name_ << " was destroyed!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	ClapTrap::operator=(other);
	std::cout << "Assignation operator called for ScavTrap" << std::endl;
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap &other)
		:ClapTrap(other)
{
	std::cout << "Copy constructor called for ScavTrap" << std::endl;
	*this = other;
}

int  ScavTrap::challengeNewcomer(std::string const &target)
{
	std::string	vaulthunter[5] = {"Daaaancce", "Bad door", "What if",
							   "Old robot", "Something is coming"};
	int  idx;

	if (energy_points_ < 25)
	{
		display_ep();
		std::cout << "Sorry you have " << energy_points_ << " energy points, you should have at least 25 energy points!" << std::endl;
		return 0;
	}
	else
	{
		energy_points_ -= 25;
		display_ep();
		idx = rand() % 5;
		std::cout << "You activate " << vaulthunter[idx] << " against " << target << std::endl;
		std::cout << "\nScavTrap " << name_ ;
		if (idx == 0)
		{
			std::cout << ": You want to come?\nYES? YOU\nDo you want to come\n???"
						"\nThen...\nLets DANCE!!!!\nTO-DO-DO DO-DO\nTO-DO-DO DO-DO" << std::endl;
		}
		else if (idx == 1)
		{
			std::cout << ": Why do you want to come?\n This is bad door,"
						" very bad door\nvery very bad door\nYou should go...\ngo......" << std::endl;
		}
		else if (idx == 2)
		{
			std::cout << ": Do you want to come?\n Why?\nWhat if there is nothing behind this door"
						"\nNo light\nNo life\nJust ... nothing ..." << std::endl;
		}
		else if (idx == 3)
		{
			std::cout << ": You want to come?\nOhhh, I'm so old, soooo oooold robot\n"
				"I can't even turn the door handle\nSo tired...\nSo old..." << std::endl;
		}
		else if (idx == 4)
		{
			std::cout << ": What?\n\n..\n\nDoor??\nAre you out of your mind?\n"
						 "run, fools, run\n\n..\n" << std::endl;
		}
	}
	return 1;
}

