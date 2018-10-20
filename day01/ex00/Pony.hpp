/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:28:42 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/03 16:28:44 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
#define PONY_HPP

#include <iostream>

class Pony
{
public:
	void	set_name(void);
	void	set_age_in_years(void);
	void	set_breed(void);
	void	set_weight_in_kg(void);
	void	set_height_in_sm(void);

	Pony();
	~Pony(void);

	std::string		get_name(void);
	std::string		get_age_in_years(void);
	std::string		get_breed(void);
	std::string		get_weight_in_kg(void);
	std::string		get_height_in_sm(void);

private:
	std::string		name_;
	std::string		age_in_years_;
	std::string		breed_;
	std::string		weight_in_kg_;
	std::string		height_in_sm_;
};

#endif
