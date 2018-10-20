/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 21:46:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/05 21:46:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
public:
	NinjaTrap(std::string name);
	~NinjaTrap();
	NinjaTrap &operator=(const NinjaTrap &other);
	NinjaTrap(const NinjaTrap &other);

	void  ninjaShoebox(ClapTrap &clap_trap);
	void  ninjaShoebox(FragTrap &frag_trap);
	void  ninjaShoebox(ScavTrap &scan_trap);
	void  ninjaShoebox(NinjaTrap &ninja_trap);
};


#endif
