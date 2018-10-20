/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 20:43:02 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/03 20:43:04 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int main()
{
	Human		Clara;
	Human		Jack;
	Human		Bob;
	Human		Anna;

	Clara.set_gender("women");
	Clara.set_age(52);
	Clara.set_brain_relative_density(0.56);
	Clara.set_test_points(57);

	Jack.set_gender("man");
	Jack.set_age(35);
	Jack.set_brain_relative_density(0.64);
	Jack.set_test_points(71);

	Bob.set_gender("man");
	Bob.set_age(24);
	Bob.set_brain_relative_density(0.71);
	Bob.set_test_points(82);

	Anna.set_gender("woman");
	Anna.set_age(19);
	Anna.set_brain_relative_density(0.69);
	Anna.set_test_points(79);

	std::cout << "Hi! This is the data from the experiment on the relationship between"
			  " relative density of synaptic contacts between neurons of brain and the results of the brain activity test. " << std::endl;
	std::cout << "\nClara (" << Clara.get_gender() << ", " << Clara.get_age() <<
			" age) have relative density of synaptic contacts between neurons " <<
			Clara.get_brain_relative_density() << " and get " << Clara.get_test_points()
			<< " points on test." << std::endl;
	std::cout << "Clara address in memory: " << Clara.identify() << std::endl;
	std::cout << "Clara address in memory: " << Clara.getBrain().identify() << std::endl;

	std::cout << "\nJack (" << Jack.get_gender() << ", " << Jack.get_age() <<
			" age) have relative density of synaptic contacts between neurons " <<
			Jack.get_brain_relative_density() << " and get " << Jack.get_test_points()
			<< " points on test." << std::endl;
	std::cout << "Jack address in memory: " << Jack.identify() << std::endl;
	std::cout << "Jack address in memory: " << Jack.getBrain().identify() << std::endl;

	std::cout << "\nBob (" << Bob.get_gender() << ", " << Bob.get_age() <<
			" age) have relative density of synaptic contacts between neurons " <<
			Bob.get_brain_relative_density() << " and get " << Bob.get_test_points()
			<< " points on test." << std::endl;
	std::cout << "Bob address in memory: " << Bob.identify() << std::endl;
	std::cout << "Bob address in memory: " << Bob.getBrain().identify() << std::endl;

	std::cout << "\nAnna (" << Anna.get_gender() << ", " << Anna.get_age() <<
			" age) have relative density of synaptic contacts between neurons " <<
			Anna.get_brain_relative_density() << " and get " << Anna.get_test_points()
			  << " points on test." << std::endl;
	std::cout << "Anna address in memory: " << Anna.identify() << std::endl;
	std::cout << "Anna address in memory: " << Anna.getBrain().identify() << std::endl;
}
