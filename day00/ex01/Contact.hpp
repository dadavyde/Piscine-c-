/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 12:47:29 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/01 12:47:30 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

#define COLUMN_WIDTH 10

class Contact
{
public:
	void	fill_contact();

	const std::string &getFirst_name() const;
	const std::string &getLast_name() const;
	const std::string &getNickname() const;
	void	print_contact_data();

private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string login;
	std::string postal_address;
	std::string email_address;
	std::string phone_number;
	std::string birthday_date;
	std::string favorite_meal;
	std::string underwear_color;
	std::string darkest_secret;
};

#endif
