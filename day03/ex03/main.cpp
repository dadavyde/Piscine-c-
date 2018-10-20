/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:16:42 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/05 17:16:43 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

int main()
{
	ClapTrap  clap("Claper");
	FragTrap  frag("Frager");
	ScavTrap  scav("Scaver");
	NinjaTrap ninja("Don Ninja");
	NinjaTrap ninja2("Son Ninja");

	srand(time(0));

	std::cout << "\t\t*****\nHey there, watch out\nNinja-shoes-box is here..\n" << std::endl;
	ninja.ninjaShoebox(ninja2);
	ninja.ninjaShoebox(clap);
	ninja.ninjaShoebox(frag);
	ninja.ninjaShoebox(scav);
	std::cout << "\nOh, he is gone\n\t\t*****\n" << std::endl;
	return 0;
}
