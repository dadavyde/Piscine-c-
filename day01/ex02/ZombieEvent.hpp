/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 19:46:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/09/17 19:46:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include "Zombie.hpp"
#include <iostream>
void	randomChump(void);

class ZombieEvent
{
public:
	void		setZombieType();
	Zombie*		newZombie(std::string name);
	std::string	get_type_of_zombie();
private:
	std::string	type_of_zombie_;
};


#endif
