/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:57:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/05 18:57:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	name_ = name;
	hit_points_ = 100;
	max_hit_points_ = 100;
	level_ = 1;
	std::cout << "ClapTrap " << name_ << " was created!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name_ << " was destroyed!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Assignation operator called for ClapTrap" << std::endl;
	if (this != &other)
	{
		this->hit_points_ = other.hit_points_;
		this->max_hit_points_ = other.max_hit_points_;
		this->level_ = other.level_;
		this->name_ = other.name_;
	}
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy constructor called for ClapTrap" << std::endl;
	*this = other;
}

void ClapTrap::rangedAttack(std::string const &target)
{
	std::cout << "ClapTrap " << name_ << " attacks " << target
			  << " at range, causing " << ranged_attack_damage_ << " points of damage!" << std::endl;
	std::cout << "\nYou're listening to 'Short-Range Damage Radio!\nChk-chk, BOOM!\n" << std::endl;

}

void  ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << "ClapTrap " << name_ << " attacks " << target
			  << " at melee, causing " << melee_attack_damage_ << " points of damage!" << std::endl;
	std::cout << "\n\"Ready for the PUNCHline?!\nPain school is now in session\n" << std::endl;
}

int  ClapTrap::takeDamage(unsigned int amount){
	hit_points_ -= (amount - armor_damage_reduction_);
	std::cout << "ClapTrap " << name_ << " was attacked by enemy with " << amount << " points of damage!" << std::endl;
	if (hit_points_ < 0)
	{
		hit_points_ = 0;
		display_hp();
		std::cout << "\n" << name_ << ": I'll stop talking when I'm dead!\n" << std::endl;
		std::cout << "ClapTrap " << name_ << " was died.\n" << std::endl;
		return 0;
	}
	display_hp();
	std::cout << "\nMy robotic flesh! AAHH!\n" << std::endl;
	return 1;
}
void  ClapTrap::beRepaired(unsigned int amount)
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

void ClapTrap::display_hp()
{
	std::cout << "HP = " << hit_points_ << '/' << max_hit_points_ << std::endl;
}

void ClapTrap::display_ep()
{
	std::cout << "EP = " << energy_points_ << '/' << max_energy_points_ << std::endl;
}

int ClapTrap::get_hp()
{
	return hit_points_;
}

std::string ClapTrap::get_name()
{
	return name_;
}
