/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:53:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/09/23 16:53:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{

public:
	Brain();
	~Brain();
	std::string		identify();
	void			set_relative_density(double relative_density);
	double			get_relative_density();

private:
	double			relative_density_of_synaptic_contacts_between_neurons;
	std::string		*mem_adr;
};

#endif
