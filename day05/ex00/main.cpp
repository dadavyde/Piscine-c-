/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:12:15 by dadavyde          #+#    #+#             */
/*   Updated: 2018/10/09 19:12:17 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat *Joy;
    Bureaucrat Mike("Mike", 120);

    try
    {
        std::cout << "Try to create Joy with grade = 151" << std::endl;
        Joy = new Bureaucrat ("Joy", 151);
        std::cout << *Joy << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

        delete Joy;
    try
    {
        std::cout << "Try to create Joy with grade = 150" << std::endl;
        Joy = new Bureaucrat ("Joy", 150);
        std::cout << *Joy << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "Try to decremaet Joy's grade" << std::endl;
        (*Joy)--;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
        std::cout << *Joy << std::endl;
        Mike = *Joy;
    try
    {
        std::cout << "Try to increment Joy's grade" << std::endl;
        (*Joy)++;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << *Joy << std::endl;
    Mike = *Joy;
    delete Joy;

}
