/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:57:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/05 18:57:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <ctime>

class ClapTrap
{
public:
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap &operator=(const ClapTrap &other);
	ClapTrap(const ClapTrap &other);

	void  rangedAttack(std::string const & target);
	void  meleeAttack(std::string const & target);
	int   takeDamage(unsigned int amount);
	void  beRepaired(unsigned int amount);
	void  display_hp();
	void  display_ep();
	int   get_hp();
	std::string  get_name();

protected:
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


#endif //EX02_CLAPTRAP_HPP
