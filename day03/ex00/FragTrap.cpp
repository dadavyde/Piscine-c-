/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 20:42:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/04 20:42:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
{
	name_ = name;
	hit_points_ = 100;
	max_hit_points_ = 100;
	energy_points_ = 100;
	max_energy_points_ = 100;
	level_ = 1;
	melee_attack_damage_ = 30;
	ranged_attack_damage_ = 20;
	armor_damage_reduction_ = 5;
	std::cout << "FR4G-TP " << name_ << " was created!" << std::endl;
	display_hp();
	display_ep();
	std::cout << "level: " << level_ << "\nmelee attack damage = " << melee_attack_damage_
	<< ", ranged attack damage = " << ranged_attack_damage_ << ", armor damage reduction = "
	<< armor_damage_reduction_ << "\n" <<  std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FR4G-TP " << name_ << " was destroyed!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	std::cout << "Assignation operator called for FR4G-TP" << std::endl;
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

FragTrap::FragTrap(const FragTrap &other)
{
	std::cout << "Copy constructor called for FR4G-TP" << std::endl;
	*this = other;
}

void FragTrap::rangedAttack(std::string const &target)
{
	std::cout << "FR4G-TP " << name_ << " attacks " << target
			  << " at range, causing " << ranged_attack_damage_ << " points of damage!" << std::endl;
	std::cout << "\nYou're listening to 'Short-Range Damage Radio!\nChk-chk, BOOM!\n" << std::endl;
	//FR4G-TP <name> attacks <target> at range, causing <damage>

}

void  FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << name_ << " attacks " << target
			  << " at melee, causing " << melee_attack_damage_ << " points of damage!" << std::endl;
	std::cout << "\n\"Ready for the PUNCHline?!\nPain school is now in session\n" << std::endl;
}

int  FragTrap::takeDamage(unsigned int amount){
	hit_points_ -= (amount - armor_damage_reduction_);
	std::cout << "FR4G-TP " << name_ << " was attacked by enemy with " << amount << " points of damage!" << std::endl;
	if (hit_points_ < 0)
	{
		hit_points_ = 0;
		display_hp();
		std::cout << "\nI'll stop talking when I'm dead!\n" << std::endl;
		std::cout << "FR4G-TP " << name_ << " was died.\n" << std::endl;
		return 0;
	}
	display_hp();
	std::cout << "\nMy robotic flesh! AAHH!\n" << std::endl;
	return 1;
}
void  FragTrap::beRepaired(unsigned int amount)
{
	if (hit_points_ < max_hit_points_)
	{
		hit_points_ += amount;
		std::cout << "Sweet life juice!" << std::endl;
		if(hit_points_ > max_hit_points_)
			hit_points_ = max_hit_points_;
		display_hp();
	}
}

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	std::string	vaulthunter[9] = {"Blight Bot", "Funzerking", "Mechromagician",
								"Rubber Ducky", "Shhhhhhhhhhh...trap", "Miniontrap",
								"Meat Unicycle", "Medbot", "Senseless Sacrifice"};
	int  idx;

	if (energy_points_ < 25)
	{
		display_ep();
		std::cout << "Sorry you have " << energy_points_ << " energy points, you should have at least 25 energy points!" << std::endl;
	}
	else
	{
		energy_points_ -= 25;
		display_ep();
		idx = rand() % 9;
		std::cout << "You activate " << vaulthunter[idx] << " against " << target << std::endl;
		std::cout << "\nFR4G-TP " << name_ ;
		if (idx == 0)
		{
			std::cout << " summons a Sirentrap emitting an acid gas"
						" and with fire wings on its back, which proceeds to fly"
						" around enemies dealing incendiary and corrosive damage."
						"\nYour attack causing 42 points of damage to enemies!" << std::endl;
			takeDamage(6);
		}
		else if (idx == 1)
		{
			std::cout << " receives a copy of his currently equipped weapon"
						" in his other clamp. Both guns are automatically fired and"
						" reloaded until the end of the skill."
						" Ammo for the equipped weapon regenerates during the package"
						" (excluding rocket launchers)."
						"\nYour attack causing 50 points of damage to enemies!" << std::endl;
			takeDamage(9);
		}
		else if (idx == 2)
		{
			std::cout << "Claptrap summons a Punkbot, which engages enemies in combat."
						" Gun accuracy and magazine size are reduced by a third, but gun damage"
						" is increased by approximately 263%. Bullets also bounce off of walls towards enemies."
						"\nYour attack causing 47 points of damage to enemies!" << std::endl;
			takeDamage(16);
		}
		else if (idx == 3)
		{
			std::cout << "Claptrap will continually bounce into the air and gain"
						" bullet reflection. Damage-over-time, melee attacks, grenades and"
						" rockets can still damage Claptrap, however."
						"\nYour attack causing 32 points of damage to enemies!" << std::endl;
			takeDamage(17);
		}
		else if (idx == 4)
		{
			std::cout << "Claptrap deploys a Holotrap and becomes invisible."
						" The hologram attracts aggro from nearby enemies. "
						"Enemies will not deliberately target Claptrap himself for"
						" the duration of this effect, though flying bullets and"
						" splash damage will still injure him. Claptrap is free to"
						" attack as many times as he likes without breaking stealth."
						"\nYour attack causing 52 points of damage to enemies!" << std::endl;
			takeDamage(0);
		}
		else if (idx == 5)
		{
			std::cout << "Claptrap throws out a Turrettrap that shoots explosive rockets"
												" and wields a Dahl assault rifle, periodically shooting powerful"
												" non-elemental bullets at its chosen target.."
												"\nYour attack causing 45 points of damage to enemies!" << std::endl;
			takeDamage(23);
		}
		else if (idx == 6)
		{
			std::cout << "Claptrap pulls out a Buzz Axe for melee combat. The fire button"
						" slashes horizontally, while the aim button slashes vertically."
						" Claptrap also periodically emits incendiary novas, and gains"
						" increased movement speed."
						"\nYour attack causing 53 points of damage to enemies!" << std::endl;
			takeDamage(32);
		}
		else if (idx == 7)
		{
			std::cout << "Claptrap gains drastically increased movement speed and"
						" a healing laser that he can use to restore teammate and enemy health."
						"\nYour attack causing 0 points of damage to enemies!" << std::endl;
			takeDamage(22);
		}
		else if (idx == 8)
		{
			std::cout << "Claptrap forces himself into Fight For Your Life to revive"
						" all other team members that are currently in Fight For Your Life."
						"\nYour attack causing 67 points of damage to enemies!" << std::endl;
			takeDamage(38);
		}
	}
}

void FragTrap::display_hp()
{
	std::cout << "HP = " << hit_points_ << '/' << max_hit_points_ << std::endl;
}

void FragTrap::display_ep()
{
	std::cout << "EP = " << energy_points_ << '/' << max_energy_points_ << std::endl;
}

int FragTrap::get_hp()
{
	return hit_points_;
}