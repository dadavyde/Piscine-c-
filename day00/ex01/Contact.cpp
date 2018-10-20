/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 12:47:13 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/01 12:47:22 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::fill_contact()
{
	std::cout << "	Enter the first name:" << std::endl;
	std::getline (std::cin, first_name);
	if (std::cin.eof()==1)
		exit(0);
	std::cout << "	Enter the last_name:" << std::endl;
	std::getline (std::cin, last_name);
	if (std::cin.eof()==1)
		exit(0);
	std::cout << "	Enter the nickname:" << std::endl;
	std::getline (std::cin, nickname);
	if (std::cin.eof()==1)
		exit(0);
	std::cout << "	Enter the login:" << std::endl;
	std::getline (std::cin, login);
	if (std::cin.eof()==1)
		exit(0);
	std::cout << "	Enter the postal address:" << std::endl;
	std::getline (std::cin, postal_address);
	if (std::cin.eof()==1)
		exit(0);
	std::cout << "	Enter the email address:" << std::endl;
	std::getline (std::cin, email_address);
	if (std::cin.eof()==1)
		exit(0);
	std::cout << "	Enter the phone number:" << std::endl;
	std::getline (std::cin, phone_number);
	if (std::cin.eof()==1)
		exit(0);
	std::cout << "	Enter the birthday date:" << std::endl;
	std::getline (std::cin, birthday_date);
	if (std::cin.eof()==1)
		exit(0);
	std::cout << "	Enter the favorite meal:" << std::endl;
	std::getline (std::cin, favorite_meal);
	if (std::cin.eof()==1)
		exit(0);
	std::cout << "	Enter the underwear color:" << std::endl;
	std::getline (std::cin, underwear_color);
	if (std::cin.eof()==1)
		exit(0);
	std::cout << "	Enter the darkest secret:" << std::endl;
	std::getline (std::cin, darkest_secret);
	if (std::cin.eof()==1)
		exit(0);
	std::cout << "\n***You created a new contact!***" << std::endl;
}

void	Contact::print_contact_data()
{
	std::cout << first_name << std::endl;
	std::cout << last_name << std::endl;
	std::cout << nickname << std::endl;
	std::cout << login << std::endl;
	std::cout << postal_address << std::endl;
	std::cout << email_address << std::endl;
	std::cout << phone_number << std::endl;
	std::cout << birthday_date << std::endl;
	std::cout << favorite_meal << std::endl;
	std::cout << underwear_color << std::endl;
	std::cout << darkest_secret << std::endl;
}

const std::string &Contact::getFirst_name() const
{
	return first_name;
}

const std::string &Contact::getLast_name() const
{
	return last_name;
}

const std::string &Contact::getNickname() const
{
	return nickname;
}
