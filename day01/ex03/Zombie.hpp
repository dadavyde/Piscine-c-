/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 19:45:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/09/17 19:45:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>

class Zombie
{
public:
	void		announce(void);
	void		set_name(std::string name);
	void		set_type(std::string type);

	Zombie();
	Zombie(std::string name, std::string type);
	~Zombie();

	std::string		name_;
	std::string		type_;

};

#endif
