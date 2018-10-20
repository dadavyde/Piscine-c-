/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 12:47:42 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/01 12:47:44 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int		main()
{
	std::string		command;
	PhoneBook		phonebook;

	std::cout << "Enter command ADD for adding new Contact, SEARCH for display "
			"a list of the available contacts or EXIT for exit program." << std::endl;
	std::getline (std::cin, command);
	while (command != "EXIT")
	{
		if (std::cin.eof()==1)
			exit(0);
		if (command == "ADD")
		{
			phonebook.add_contact();
		}
		else if (command == "SEARCH")
		{
			phonebook.print_phonebook();
		}
		std::getline(std::cin, command);
	}
}
