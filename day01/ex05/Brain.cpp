/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:53:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/09/23 16:53:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <sstream>
#include <iomanip>

Brain::Brain(): relative_density_of_synaptic_contacts_between_neurons(), mem_adr()
{}

Brain::~Brain()
{
	delete mem_adr;
}

std::string	Brain::identify()
{
	long a = (long)this;
	std::ostringstream		vStream;

	vStream << "0x" << std::hex << a;
	mem_adr = new std::string(vStream.str());
	return (*mem_adr);
}

void		Brain::set_relative_density(double relative_density)
{
	relative_density_of_synaptic_contacts_between_neurons = relative_density;
}

double		Brain::get_relative_density()
{
	return (relative_density_of_synaptic_contacts_between_neurons);
}
