/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 20:42:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/04 20:42:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <ctime>

class FragTrap
{
public:
	FragTrap(std::string name);
	~FragTrap();
	FragTrap &operator=(const FragTrap &other);
	FragTrap(const FragTrap &other);



	void  rangedAttack(std::string const & target);
	void  meleeAttack(std::string const & target);
	int   takeDamage(unsigned int amount);
	void  beRepaired(unsigned int amount);
	void  vaulthunter_dot_exe(std::string const & target);
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
