/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 12:47:53 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/01 12:47:56 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	num_of_contact = 0;
}

void	PhoneBook::print_phonebook()
{
	int		idx = 0;

	if (num_of_contact == 0)
	{
		std::cout << "Your Phonebook is empty!" << std::endl;
		return;
	}
	else
	{
		while (idx < num_of_contact)
		{
			print_contacts(idx);
			idx++;
		}
		print_one_contact();
	}
}

void	PhoneBook::print_one_contact()
{
	std::string		index;

	std::cout << "Please, enter the index of your contact:" << std::endl;
	while (1)
	{
		std::cin.clear();
		std::getline (std::cin, index);
		if (std::cin.eof()==1)
			exit(0);
		if (index.size() == 1 && check_index(index.data()[0]))
			break ;
		else
			std::cout << "Please, enter the valid index!" << std::endl;
	}
	contacts[index.data()[0] - '0'].print_contact_data();
}

int		PhoneBook::check_index(char index_num)
{
	if (index_num >= '0' && index_num < '0' + num_of_contact)
		return (1);
	else
		return (0);
}

void	PhoneBook::print_contacts(int index)
{
	std::cout << "|         " << index;
	prepare_for_print(contacts[index].getFirst_name());
	prepare_for_print(contacts[index].getLast_name());
	prepare_for_print(contacts[index].getNickname());
	std::cout << '|' << std::endl;
}

void	PhoneBook::prepare_for_print(std::string name)
{
	std::cout << '|';
	if (name.size() <= COLUMN_WIDTH)
	{
		for (int i = 0; i < (int)(COLUMN_WIDTH - name.size()); i++)
			std::cout << " ";
		std::cout << name;
	}
	else
	{
		name.erase (name.begin() + COLUMN_WIDTH - 1, name.end());
		std::cout << name << '.';
	}
}

void	PhoneBook::add_contact()
{
	if (num_of_contact >= 8)
		std::cout << "Your Phonebook is full. You cannot add new contacts anymore!" << std::endl;
	else
	{
		contacts[num_of_contact].fill_contact();
		num_of_contact++;
	}
}
