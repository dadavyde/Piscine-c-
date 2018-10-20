/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 19:35:18 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/03 19:35:20 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string		*p = &str;
	std::string		&ref = str;

	std::cout << *p << std::endl;
	std::cout << ref << std::endl;
}
