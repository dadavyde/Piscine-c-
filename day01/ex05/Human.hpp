/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 17:58:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/09/23 17:58:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Brain.hpp"

class Human
{
public:
	Human();
	~Human();
	std::string		identify();
	Brain&			getBrain();
	void			set_age(int age);
	void			set_gender(std::string gender);
	void			set_brain_relative_density(double relative_density);
	void			set_test_points(int test_points);

	int				get_age();
	std::string		get_gender();
	double			get_brain_relative_density();
	int				get_test_points();

private:
	Brain			brain_;
	int				age_;
	std::string		gender_;
	int				test_points_;
};


#endif
