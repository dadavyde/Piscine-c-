/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 12:04:09 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/01 12:04:13 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main(int argc, char **argv)
{
	int		str_num;
	int		char_num;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		str_num = 1;
		while (str_num < argc)
		{
			char_num = 0;
			while (argv[str_num][char_num] != '\0')
			{
				std::cout << (char)toupper(argv[str_num][char_num]);
				char_num++;
			}
			str_num++;
		}
		std::cout << std::endl;
	}
}
