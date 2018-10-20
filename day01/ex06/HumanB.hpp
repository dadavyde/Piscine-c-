/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 19:55:17 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/03 19:55:18 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
public:
	explicit HumanB(std::string name);
	~HumanB();
	void    attack();
	void    setWeapon(Weapon &weapon);

private:
	std::string     name_;
	Weapon          *weapon_;
};

#endif
