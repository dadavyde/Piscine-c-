/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 21:34:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/04 21:34:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <ctime>

class ScavTrap
{
public:
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap &operator=(const ScavTrap &other);
	ScavTrap(const ScavTrap &other);



	void  rangedAttack(std::string const & target);
	void  meleeAttack(std::string const & target);
	int   takeDamage(unsigned int amount);
	void  beRepaired(unsigned int amount);
	int   challengeNewcomer(std::string const & target);
	void  display_hp();
	void  display_ep();
	int   get_hp();
	std::string  get_name();



private:
	int  hit_points_;
	int  max_hit_points_;
	int  energy_points_;
	int  max_energy_points_;
	int  level_;
	std::string  name_;
	int  melee_attack_damage_;
	int  ranged_attack_damage_;
	int  armor_damage_reduction_;
};


#endif
