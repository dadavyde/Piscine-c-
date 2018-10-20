/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:28:04 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/03 16:28:28 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony()
{
	std::cout << "Pony was created" << std::endl;
}

Pony::~Pony()
{
	std::cout << "Pony " << name_ << " was deleted" << std::endl;
}

void	Pony::set_name()
{

	std::cout << "\tEnter name of your pony" << std::endl;
	std::getline (std::cin, name_);
	if (std::cin.eof()==1)
		exit(0);
	std::cout << "Pony named " << name_ << std::endl;
}

void	Pony::set_age_in_years()
{
	std::cout << "\tEnter age of your pony" << std::endl;
	std::getline (std::cin, age_in_years_);
	if (std::cin.eof()==1)
		exit(0);
	std::cout << "Pony " << name_ << "\'s " << age_in_years_ << " years old" << std::endl;
}

void	Pony::set_breed()
{
	std::cout << "\tEnter breed of your pony" << std::endl;
	std::getline (std::cin, breed_);
	if (std::cin.eof()==1)
		exit(0);
	std::cout << "Pony " << name_ << "\'s breed is " << breed_ << std::endl;
}

void	Pony::set_weight_in_kg()
{
	std::cout << "\tEnter weight in kg of your pony" << std::endl;
	std::getline (std::cin, weight_in_kg_);
	if (std::cin.eof()==1)
		exit(0);
	std::cout << "Pony " << name_ << "\'s weight is " << weight_in_kg_ << " kg" << std::endl;
}

void	Pony::set_height_in_sm()
{
	std::cout << "\tEnter height in sm of your pony" << std::endl;
	std::getline (std::cin, height_in_sm_);
	if (std::cin.eof()==1)
		exit(0);
	std::cout << "Pony " << name_ << "\'s height is " << height_in_sm_ << " sm" << std::endl;
}

std::string		Pony::get_name()
{
	return (name_);
}

std::string	Pony::get_age_in_years()
{
	return (age_in_years_);
}

std::string		Pony::get_breed()
{
	return (breed_);
}

std::string	Pony::get_weight_in_kg()
{
	return (weight_in_kg_);
}

std::string	Pony::get_height_in_sm()
{
	return (height_in_sm_);
}
