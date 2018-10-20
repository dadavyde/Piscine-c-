/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 17:20:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/09/22 17:20:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class ZombieHorde
{
public:
	ZombieHorde(int N);
	~ZombieHorde();

	void	announce(void);

private:
	Zombie	*zombies_arr;
	int		num_of_zombies_;
};

#endif
