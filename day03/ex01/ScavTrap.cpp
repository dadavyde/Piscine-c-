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

ScavTrap::ScavTrap(std::string name)
{
	name_ = name;
	hit_points_ = 100;
	max_hit_points_ = 100;
	energy_points_ = 50;
	max_energy_points_ = 50;
	level_ = 1;
	melee_attack_damage_ = 20;
	ranged_attack_damage_ = 15;
	armor_damage_reduction_ = 3;
	std::cout << "SC4V-TP " << name_ << " was created!" << std::endl;
	display_hp();
	display_ep();
	std::cout << "level: " << level_ << "\nmelee attack damage = " << melee_attack_damage_
			  << ", ranged attack damage = " << ranged_attack_damage_ << ", armor damage reduction = "
			  << armor_damage_reduction_ << "\n" <<  std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "SC4V-TP " << name_ << " was destroyed!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "Assignation operator called for SC4V-TP" << std::endl;
	if (this != &other)
	{
		this->hit_points_ = other.hit_points_;
		this->max_hit_points_ = other.max_hit_points_;
		this->energy_points_ = other.energy_points_;
		this->max_energy_points_ = other.max_energy_points_;
		this->level_ = other.level_;
		this->name_ = other.name_;
		this->melee_attack_damage_ = other.melee_attack_damage_;
		this->ranged_attack_damage_ = other.ranged_attack_damage_;
		this->armor_damage_reduction_ = other.armor_damage_reduction_;
	}
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	std::cout << "Copy constructor called for SC4V-TP" << std::endl;
	*this = other;
}

void ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << "SC4V-TP " << name_ << " attacks " << target
			  << " at range, causing " << ranged_attack_damage_ << " points of damage!" << std::endl;
	std::cout << "\nGet ready for some Fragtrap face time!!\nIn yo' FACE!\n" << std::endl;
	//FR4G-TP <name> attacks <target> at range, causing <damage>

}

void  ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "SC4V-TP " << name_ << " attacks " << target
			  << " at melee, causing " << melee_attack_damage_ << " points of damage!" << std::endl;
	std::cout << "\n\"Guess who?\nMeet professor punch!\n" << std::endl;
}

int  ScavTrap::takeDamage(unsigned int amount){
	hit_points_ -= (amount - armor_damage_reduction_);
	std::cout << "SC4V-TP " << name_ << " was attacked by enemy with " << amount << " points of damage!" << std::endl;
	if (hit_points_ < 0)
	{
		hit_points_ = 0;
		display_hp();
		std::cout << "\nI'll die the way I lived: annoying!\n" << std::endl;
		std::cout << "SC4V-TP " << name_ << " was died.\n" << std::endl;
		return 0;
	}
	display_hp();
	std::cout << "\nWoah! Oh! Jeez!\n" << std::endl;
	return 1;
}
void  ScavTrap::beRepaired(unsigned int amount)
{
	if (hit_points_ < max_hit_points_)
	{
		hit_points_ += amount;
		std::cout << "I found health!" << std::endl;
		if(hit_points_ > max_hit_points_)
			hit_points_ = max_hit_points_;
		display_hp();
	}
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
		std::cout << "\nSC4V-TP " << name_ ;
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
		return 1;
	}
}

void ScavTrap::display_hp()
{
	std::cout << "HP = " << hit_points_ << '/' << max_hit_points_ << std::endl;
}

void ScavTrap::display_ep()
{
	std::cout << "EP = " << energy_points_ << '/' << max_energy_points_ << std::endl;
}

int ScavTrap::get_hp()
{
	return hit_points_;
}

std::string ScavTrap::get_name()
{
	return name_;
}
