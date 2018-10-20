/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 21:46:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/05 21:46:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name)
{
	hit_points_ = 60;
	max_hit_points_ = 60;
	energy_points_ = 120;
	max_energy_points_ = 120;
	melee_attack_damage_ = 60;
	ranged_attack_damage_ = 5;
	armor_damage_reduction_ = 0;

	std::cout << "NinjaTrap " << name_ << " was created!" << std::endl;
	display_hp();
	display_ep();
	std::cout << "level: " << level_
			  << "\nmelee attack damage = " << melee_attack_damage_
			  << "\nranged attack damage = " << ranged_attack_damage_
			  << "\narmor damage reduction = " << armor_damage_reduction_ << "\n" <<  std::endl;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "NinjaTrap " << name_ << " was destroyed!" << std::endl;
}

NinjaTrap& NinjaTrap::operator=(const NinjaTrap &other)
{
	ClapTrap::operator=(other);
	std::cout << "Assignation operator called for FragTrap" << std::endl;
	return (*this);
}

NinjaTrap::NinjaTrap(const NinjaTrap & other)
		:ClapTrap(other)
{
	std::cout << "Copy constructor called for NinjaTrap" << std::endl;
	*this = other;
}

void NinjaTrap::ninjaShoebox(NinjaTrap &ninja_trap)
{
	std::cout << "\n" <<  name_ << " and " << ninja_trap.get_name()
	<< " change their shoes among themselves." << std::endl;
}

void NinjaTrap::ninjaShoebox(ClapTrap &clap_trap)
{
	std::cout << "\n" <<  name_ << " change shoes of " << clap_trap.get_name()
			  << " to dancing shoes.\nDance, baby, dance!!!" << std::endl;
}

void NinjaTrap::ninjaShoebox(FragTrap &frag_trap)
{
	std::cout << "\n" <<  name_ << " change shoes of " << frag_trap.get_name()
			  << " on moon rovers\nFly to the mooooon..." << std::endl;
}
void NinjaTrap::ninjaShoebox(ScavTrap &scan_trap)
{
	std::cout << "\n" <<  name_ << " change shoes of " << scan_trap.get_name()
			  << " on rollers.\nLETS ROOOLLLLLLL" << std::endl;
}



