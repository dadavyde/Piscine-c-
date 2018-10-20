/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 17:58:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/09/23 17:58:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human() : brain_(), age_(), gender_(), test_points_()
{}

Human::~Human()
{}

std::string	Human::identify()
{
	return (brain_.identify());
}

void		Human::set_age(int age)
{
	age_ = age;
}

void		Human::set_gender(std::string gender)
{
	gender_ = gender;
}

void		Human::set_brain_relative_density(double relative_density)
{
	brain_.set_relative_density(relative_density);
}

void		Human::set_test_points(int test_points)
{
	test_points_ = test_points;
}

Brain&		Human::getBrain()
{
	return (brain_);
}

int			Human::get_age()
{
	return(age_);
}

std::string	Human::get_gender()
{
	return (gender_);
}

double Human::get_brain_relative_density()
{
	return (brain_.get_relative_density());
}

int Human::get_test_points()
{
	return (test_points_);
}