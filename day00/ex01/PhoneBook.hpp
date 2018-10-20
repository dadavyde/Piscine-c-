/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 12:48:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/01 12:48:02 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cctype>

class PhoneBook
{
public:
	PhoneBook();
	void	print_phonebook();
	void	print_contacts(int index);
	void	prepare_for_print(std::string name);
	void	add_contact();
	void	print_one_contact();
	int		check_index(char index_num);

private:
	Contact		contacts[8];
	int			num_of_contact;
};

#endif
