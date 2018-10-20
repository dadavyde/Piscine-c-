/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:28:50 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/03 16:28:52 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void	ponyOnTheHeap(int num)
{
	Pony	*my_little_pony;

	std::cout << "\n***The first line of the function ponyOnTheHeap***\n" << std::endl;
	my_little_pony = new Pony[num];
	for (int i = 0; i < num; i++)
	{
		my_little_pony[i].set_name();
		my_little_pony[i].set_age_in_years();
		my_little_pony[i].set_breed();
		my_little_pony[i].set_height_in_sm();
		my_little_pony[i].set_weight_in_kg();
	}
	delete [] my_little_pony;
	std::cout << "\n***The last line of the function ponyOnTheHeap***\n" << std::endl;
}

void	ponyOnTheStack(int num)
{
	Pony	my_little_pony[num];

	std::cout << "\n***The first line of the function ponyOnTheStack***\n" << std::endl;
	for (int i = 0; i < num; i++)
	{
		my_little_pony[i].set_name();
		my_little_pony[i].set_age_in_years();
		my_little_pony[i].set_breed();
		my_little_pony[i].set_height_in_sm();
		my_little_pony[i].set_weight_in_kg();
	}
	std::cout << "\n***The last line of the function ponyOnTheStack***\n" << std::endl;
}

int main()
{
	std::cout << "\nCall ponyOnTheHeap" << std::endl;
	ponyOnTheHeap(1);
	std::cout << "\nCall ponyOnTheStack\n" << std::endl;
	ponyOnTheStack(1);
	std::cout << std::endl;
	return 0;
}
