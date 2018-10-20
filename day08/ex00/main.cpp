/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:05:03 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/13 17:05:04 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <deque>
#include "easyfind.hpp"

int  main()
{
    int myints[] = {10, 20, 30, 40};
    std::vector<int> v (myints,myints+4);

    int i = easyfind(v, 30);
    if (i == -1)
        std::cout << "Value can't be found" << std::endl;
    else
        std::cout << "Index = " << i << ", v[i] = " << v[i] << std::endl;
    i = easyfind(v, 60);
    if (i == -1)
        std::cout << "Value can't be found" << std::endl;
    else
        std::cout << "Index = " << i << ", v[i] = " << v[i] << std::endl;

    std::deque<int> l (myints, myints + sizeof(myints) / sizeof(int) );

    i = easyfind(l, 60);
    if (i == -1)
        std::cout << "Value can't be found" << std::endl;
    else
        std::cout << "Index = " << i << std::endl;
    i = easyfind(l, 20);
    if (i == -1)
        std::cout << "Value can't be found" << std::endl;
    else
        std::cout << "Index = " << i << " l[i] = " << l[i] << std::endl;
}

